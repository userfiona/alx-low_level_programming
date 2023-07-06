#include <stdlib.h>

typedef struct hash_table {
    unsigned long int size;
    /* other members of the hash table structure */
} hash_table_t;

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the hash table array.
 *
 * Return: A pointer to the newly created hash table,
 *         or NULL if something went wrong.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *table = malloc(sizeof(hash_table_t));

    if (table == NULL)
    {
        /* Error: Unable to allocate memory for the hash table */
        return NULL;
    }

    table->size = size;
    /* Initialize other members of the hash table structure here */

    return table;
}

