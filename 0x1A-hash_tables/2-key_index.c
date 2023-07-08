#include "hash_tables.h"

/**
 * key_index - Calculates the index for a key/value pair in the hash table array.
 * @key: The key used for hashing.
 * @size: The size of the hash table array.
 *
 * Return: The index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash_value = hash_djb2(key);
    unsigned long int index = hash_value % size;

    return index;
}
