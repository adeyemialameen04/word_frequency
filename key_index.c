#include "hash_table.h"

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hashed_key = hash_djb2(key) % size;

	return (hashed_key);
}
