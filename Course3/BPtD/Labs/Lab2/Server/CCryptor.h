#ifndef CCRYPTOR_H
#define CCRYPTOR_H

#include <memory>
#include <string>
#include <openssl/ossl_typ.h>

class CCryptor
{
public:
	CCryptor();
	~CCryptor();

	void Encrypt(char* result, const char* source) const;
	void Decrypt(char* result, const char* source) const;

	void GetPublicKey(char* dest) const;

	int GetBufferLength() const;

	static void ToBase64(char* result, const char* source, size_t length);
	static int FromBase64(char* result, const char* source);

private:
	RSA* rsa_;

	CCryptor(const CCryptor&) = delete;
	CCryptor(CCryptor&&) = delete;
	CCryptor operator=(const CCryptor&) = delete;
	CCryptor operator=(CCryptor&&) = delete;
};

#endif // CCRYPTOR_H
