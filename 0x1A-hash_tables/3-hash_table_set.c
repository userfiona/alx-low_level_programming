#include "hash_tables.h"

/**
 * hash_table_set - Adds an item to a hash table
 * @ht: The hash table
 * @key: Key of the item
 * @value: Value of the item
 *
 * Return: 1 for success, 0 for failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *tmp_node;

	if (!ht || !key || !(*key))
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	tmp_node = ht->array[index];
	while (tmp_node)
	{
		if (strcmp(tmp_node->key, key) == 0)
		{
			free(tmp_node->value);
			tmp_node->value = strdup(value);
			return (1);
		}
		tmp_node = tmp_node->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
