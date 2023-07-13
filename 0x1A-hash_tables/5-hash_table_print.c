#include "hash_tables.h"

/**
 * hash_table_print - Function that prints a hash table.
 * @ht: Pointer to hash table to be printed.
 *
 * Return: No return.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i = 0;
	int first_entry = 1;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (first_entry)
			{
				printf("'%s': '%s'", node->key, node->value);
				first_entry = 0;
			}
			else
			{
				printf(", '%s': '%s'", node->key, node->value);
			}
			node = node->next;
		}
	}

	printf("}\n");
}
