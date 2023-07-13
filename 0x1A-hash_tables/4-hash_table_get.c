#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 *
 * @ht: Pointer to the hash table
 * @key: Key of the hash
 * Return: Value of the hash.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int k_index;
	hash_node_t *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	k_index = key_index((unsigned char *)key, ht->size);

	tmp = ht->array[k_index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return tmp->value;
		tmp = tmp->next;
	}

	return NULL;
}
