#include "hash_tables.h"

typedef struct hash_node {
    char *key;
    char *value;
    struct hash_node *next;
} hash_node_t;

typedef struct hash_table {
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add/update the key/value pair.
 * @key: The key to be added/updated.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    unsigned long int index = key_index((const unsigned char *)key, ht->size);
    hash_node_t *new_node = (hash_node_t *)malloc(sizeof(hash_node_t));

    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    new_node->value = strdup(value);

    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return 0;
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}
