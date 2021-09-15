#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "rsacrypt.h"

int get_prime(int position)
{
	int* is_prime = (int*)calloc(sizeof(int), position);

	for(int i = 1; 3 * i + 1 < position; i++)
		for(int j = 1, k; (k = i + j + 2 * i * j) < position && j <= i; j++)
			is_prime[k] = 1;

	int result;
	for(int i = position - 1; i >= 1; i--)
		if(!is_prime[i])
		{
			result = 2 * i + 1;
			break;
		}

	free(is_prime);
	return result;
}

uint32_t rand_key()
{
	return rand() % 50 + 50;
}

uint32_t gcd(uint32_t lhs, uint32_t rhs)
{
	uint32_t temp;
	while (rhs)
	{
		temp = lhs % rhs;
		lhs = rhs;
		rhs = temp;
	}
	return abs(lhs);
}

crypt_key_t rsa_generate_keys()
{
	srand(time(0));

	uint32_t p = get_prime(rand_key());
	uint32_t q;
	do
		 q = get_prime(rand_key());
	while(p == q);

	uint32_t f = (p - 1) * (q - 1);
	uint32_t n = p * q;

	uint32_t d, e = 0;

	do
		d = rand() % n + n / 2;
	while(gcd(d, f) != 1);

	do
		e++;
	while ((e * d) % f != 1);

	crypt_key_t crypt_key;
	crypt_key.e = e;
	crypt_key.d = d;
	crypt_key.n = n;
	return crypt_key;
}

void rsa_encrypt(uint32_t* crypted, const char* data, int size, crypt_key_t crypt_key)
{
	uint32_t b = 301;
	uint32_t cip;
	for (uint32_t j = 0; j <= size; j++)
	{
		cip = 1;
		uint32_t i = 0;
		while (i < crypt_key.e)
		{
			cip *= (uint32_t)(data[j]) + b;
			cip %= crypt_key.n;
			i++;
		}
		crypted[j] = cip;
		b++;
	}
}

void rsa_decrypt(char* data, const uint32_t* crypted, int size, crypt_key_t crypt_key)
{
	uint32_t b = 301;
	uint32_t chr;
	for (uint32_t j = 0; j < size; j++)
	{
		chr = 1;
		uint32_t i = 0;
		while (i < crypt_key.d)
		{
			chr *= crypted[j];
			chr %= crypt_key.n;
			i++;
		}
		chr -= b;
		data[j] = (char)chr;
		b++;
	}
}
