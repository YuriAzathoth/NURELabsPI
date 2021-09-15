#ifndef RSACRYPT_H
#define RSACRYPT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct crypt_key_s
{
	uint32_t e;
	uint32_t d;
	uint32_t n;
} crypt_key_t;

crypt_key_t rsa_generate_keys();
void rsa_encrypt(uint32_t* crypted, const char* data, int size, crypt_key_t crypt_key);
void rsa_decrypt(char* data, const uint32_t* crypted, int size, crypt_key_t crypt_key);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // RSACRYPT_H
