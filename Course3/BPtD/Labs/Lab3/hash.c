#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

static const char HASH_BRUTE_TABLE_BEGIN[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
static const char* HASH_BRUTE_TABLE_END = HASH_BRUTE_TABLE_BEGIN + sizeof(HASH_BRUTE_TABLE_BEGIN) / sizeof(char);

uint8_t hash_text(const char* text, unsigned length)
{
	uint16_t hash = 0xDEAD;

	for (unsigned i = 0; i < length; ++i)
		hash ^= ~text[i] * text[i];

	return (hash & 255) ^ (hash & (255 << 8));
}

static int hash_brute_impl(char* candidate_pos,
						   const char* candidate_begin,
						   const char* candidate_end,
						   const char* original,
						   unsigned length,
						   uint8_t hash,
						   unsigned stage_max,
						   unsigned stage_curr)
{
	const char* brute_pos;
	char temp;
	while (candidate_pos < candidate_end)
	{
		for (brute_pos = HASH_BRUTE_TABLE_BEGIN; brute_pos <= HASH_BRUTE_TABLE_END; ++brute_pos)
			if (*candidate_pos != *brute_pos)
			{
				temp = *candidate_pos;
				*candidate_pos = *brute_pos;
				if (stage_curr < stage_max)
				{
					if (hash_brute_impl(candidate_pos + 1, candidate_begin, candidate_end, original, length, hash, stage_max, stage_curr + 1) != -1)
						return 1;
				}
				else if (hash == hash_text(candidate_begin, length))
					return 1;
				*candidate_pos = temp;
			}
		++candidate_pos;
	}
}

int hash_brute(char* candidate, const char* original, unsigned length, uint8_t hash)
{
	memcpy(candidate, original, length);
	return hash_brute_impl(candidate, candidate, &candidate[length], original, length, hash, 2, 0);
}
