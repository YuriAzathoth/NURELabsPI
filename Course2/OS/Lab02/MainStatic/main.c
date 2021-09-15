#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rsacrypt.h>

int main()
{
	const char data[] = "Hello world!";
	const int size = strlen(data) + 1;

	uint32_t* encrypted = (uint32_t*)calloc(sizeof(uint32_t), size);
	char* decrypted = (char*)calloc(sizeof(char), size);

	crypt_key_t crypt_key = rsa_generate_keys();
	rsa_encrypt(encrypted, data, size, crypt_key);
	rsa_decrypt(decrypted, encrypted, size, crypt_key);

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
}
