#ifndef DES_H
#define DES_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void des_process(char* data, size_t length, uint64_t key, bool decrypt);
bool des_check_key(uint64_t key);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // DES_H
