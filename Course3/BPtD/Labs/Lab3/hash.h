#ifndef HASH_H
#define HASH_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

uint8_t hash_text(const char* text, unsigned length);
int hash_brute(char* candidate, const char* original, unsigned length, uint8_t hash);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // HASH_H
