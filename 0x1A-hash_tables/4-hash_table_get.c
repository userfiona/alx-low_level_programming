#include "hash_tables.h"

char *hash_table_get(const hash_table_t *ht, const char *key)
{
    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    unsigned long int index = key_index((const unsigned char *)key, ht->size);
    hash_node_t *current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;

        current = current->next;
    }

    return NULL;
}
