#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
    if (ht == NULL)
        return;

    int printed = 0;

    printf("{");
    for (unsigned long int i = 0; i < ht->size; i++)
    {
        hash_node_t *current = ht->array[i];

        while (current != NULL)
        {
            if (printed > 0)
                printf(", ");

            printf("'%s': '%s'", current->key, current->value);
            printed++;
            current = current->next;
        }
    }
    printf("}\n");
}
