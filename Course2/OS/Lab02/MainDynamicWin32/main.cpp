#include <cstdint>
#include <cstdio>
#include <windows.h>
using namespace std;

typedef struct crypt_key_s
{
	unsigned int e;
	int d;
	unsigned int n;
} crypt_key_t;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const char data[] = "Hello world!";
	const int size = strlen(data) + 1;

	uint32_t* encrypted = (uint32_t*)calloc(sizeof(uint32_t), size);
	uint32_t* decrypted = (uint32_t*)calloc(sizeof(uint32_t), size);

	HINSTANCE hMainDll = LoadLibrary("libMainDll.dll");

    typedef crypt_key_t (*fn_generate_key_t)();
	fn_generate_key_t pfn_rsa_generate_keys = (fn_generate_key_t)GetProcAddress(hMainDll, "rsa_generate_keys");

	typedef void (*fn_rsa_encrypt_t)(uint32_t*, const char*, int, crypt_key_t);
	fn_rsa_encrypt_t pfn_rsa_encrypt = (fn_rsa_encrypt_t)GetProcAddress(hMainDll, "rsa_encrypt");

	typedef void (*fn_rsa_decrypt_t)(uint32_t*, uint32_t*, int, crypt_key_t);
	fn_rsa_decrypt_t pfn_rsa_decrypt = (fn_rsa_decrypt_t)GetProcAddress(hMainDll, "rsa_decrypt");

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

	printf("Decrypted: ");
	for (int i = 0; i < size; i++)
		printf("%c", (char)decrypted[i]);
	printf("\n");

	free(encrypted);
	free(decrypted);

	FreeLibrary(hMainDll);

	return 0;
}
