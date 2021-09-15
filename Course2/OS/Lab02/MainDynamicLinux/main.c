#include <dlfcn.h>
#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct crypt_key_s
{
	uint32_t e;
	uint32_t d;
	uint32_t n;
} crypt_key_t;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	const char data[] = "Русский текст!";

	const int size = strlen(data) + 1;

	uint32_t* encrypted = (uint32_t*)calloc(sizeof(uint32_t), size);
	char* decrypted = (char*)calloc(sizeof(char), size);

	void* hLibrary = dlopen("libMainDll.so", RTLD_LAZY);
	if (!hLibrary)
        printf("%s\n", dlerror());

    typedef crypt_key_t (*fn_generate_key_t)();
	fn_generate_key_t pfn_rsa_generate_keys = (fn_generate_key_t)dlsym(hLibrary, "rsa_generate_keys");

	typedef void (*fn_rsa_encrypt_t)(uint32_t*, const char*, int, crypt_key_t);
	fn_rsa_encrypt_t pfn_rsa_encrypt = (fn_rsa_encrypt_t)dlsym(hLibrary, "rsa_encrypt");

	typedef void (*fn_rsa_decrypt_t)(char*, uint32_t*, int, crypt_key_t);
	fn_rsa_decrypt_t pfn_rsa_decrypt = (fn_rsa_decrypt_t)dlsym(hLibrary, "rsa_decrypt");

	crypt_key_t crypt_key = (*pfn_rsa_generate_keys)();
	(*pfn_rsa_encrypt)(encrypted, data, size, crypt_key);
	(*pfn_rsa_decrypt)(decrypted, encrypted, size, crypt_key);

	printf("n = %d\n", crypt_key.n);
	printf("e = %d\n", crypt_key.e);
	printf("d = %d\n", crypt_key.d);

	printf("Data: %s\n", data);

	printf("Crypted: ");
	for (int i = 0; i < size; i++)
		printf("%d ", encrypted[i]);
	printf("\n");

	printf("Decrypted: %s\n", decrypted);

	free(encrypted);
	free(decrypted);

	dlclose(hLibrary);

	return 0;
}
