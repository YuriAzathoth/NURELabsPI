#include <string.h>
#include <stdexcept>
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include "CCryptor.h"

using namespace std;

struct BNFree { void operator()(BIGNUM* p) { BN_free(p); } };
struct BIOFreeAll { void operator()(BIO* p) { BIO_free_all(p); } };

static constexpr int RSA_PADDING = RSA_PKCS1_OAEP_PADDING;
static constexpr int RSA_BITS = 2048;

CCryptor::CCryptor()
{
	unique_ptr<BIGNUM, BNFree> bignum(BN_new());

	if (BN_set_word(bignum.get(), RSA_F4) != 1)
		throw runtime_error("OpenSSL failed to generate initial BIGNUM");

	rsa_ = RSA_new();
	if (RSA_generate_key_ex(rsa_, RSA_BITS, bignum.get(), nullptr) != 1)
		throw runtime_error("OpenSSL failed to generate RSA key pair");
}

CCryptor::~CCryptor()
{
	RSA_free(rsa_);
}

void CCryptor::Encrypt(char* result, const char* source) const
{
	char* buffer = new char[GetBufferLength()];
	const int length = RSA_public_encrypt(strlen(source), (unsigned char*)source, (unsigned char*)buffer, rsa_, RSA_PADDING);
	if (length == -1)
		throw runtime_error(string("OpenSSL failed to encrypt data:\n") + ERR_error_string(ERR_get_error(), buffer));
	ToBase64(result, buffer, length - 1);
	delete[] buffer;
}

void CCryptor::Decrypt(char* result, const char* source) const
{
	char* buffer = new char[GetBufferLength()];
	const int binlen = FromBase64(buffer, source);
	const int length = RSA_private_decrypt(binlen, (unsigned char*)buffer, (unsigned char*)result, rsa_, RSA_PADDING);
	if (length == -1)
		throw runtime_error(string("OpenSSL failed to decrypt data:\n") + ERR_error_string(ERR_get_error(), buffer));
	result[length] = '\0';
	delete[] buffer;
}

void CCryptor::GetPublicKey(char* dest) const
{
	unique_ptr<BIO, BIOFreeAll> bio(BIO_new(BIO_s_mem()));
	if (PEM_write_bio_RSA_PUBKEY(bio.get(), rsa_) != 1)
		throw runtime_error("OpenSSL failed to convert public key to PEM");

	const int length = BIO_pending(bio.get());
	BIO_read(bio.get(), dest, length);
	dest[length] = '\0';
}

int CCryptor::GetBufferLength() const
{
	return RSA_size(rsa_);
}

void CCryptor::ToBase64(char* result, const char* source, size_t length)
{
	unique_ptr<BIO, BIOFreeAll> b64(BIO_new(BIO_f_base64()));
	BIO_set_flags(b64.get(), BIO_FLAGS_BASE64_NO_NL);

	BIO* sink = BIO_new(BIO_s_mem());
	BIO_push(b64.get(), sink);
	BIO_write(b64.get(), source, length);
	BIO_flush(b64.get());

	const char* encoded;
	length = BIO_get_mem_data(sink, &encoded);
	memcpy(result, encoded, length);
	result[length] = '\0';
}

int CCryptor::FromBase64(char* result, const char* source)
{
	unique_ptr<BIO, BIOFreeAll> b64(BIO_new(BIO_f_base64()));
	BIO_set_flags(b64.get(), BIO_FLAGS_BASE64_NO_NL);

	BIO* src = BIO_new_mem_buf(source, -1);
	BIO_push(b64.get(), src);

	const int maxlen = strlen(source) / 4 * 3 + 1;
	const int length = BIO_read(b64.get(), result, maxlen);
	result[length] = '\0';

	return length;
}
