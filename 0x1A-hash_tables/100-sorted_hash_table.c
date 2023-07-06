#include "hash_tables.h"

typedef struct shash_node {
    char *key;
    char *value;
    struct shash_node *next;
    struct shash_node *prev;
} shash_node_t;

typedef struct shash_table {
    unsigned long int size;
    shash_node_t **array;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = (shash_table_t *)malloc(sizeof(shash_table_t));

    if (ht == NULL)
        return NULL;

    ht->size = size;
    ht->array = (shash_node_t **)calloc(size, sizeof(shash_node_t *));

    if (ht->array == NULL)
    {
        free(ht);
        return NULL;
    }

    return ht;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    unsigned long int index = key_index((const unsigned char *)key, ht->size);
    shash_node_t *new_node = (shash_node_t *)malloc(sizeof(shash_node_t));

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

    new_node->next = NULL;
    new_node->prev = NULL;

    if (ht->array[index] == NULL)
    {
        ht->array[index] = new_node;
    }
    else
    {
        shash_node_t *current = ht->array[index];

        while (current != NULL)
        {
            if (strcmp(current->key, key) == 0)
            {
                free(current->value);
                current->value = strdup(value);

                if (current->value == NULL)
                {
                    free(new_node->key);
                    free(new_node->value);
                    free(new_node);
                    return 0;
                }

                free(new_node->key);
                free(new_node->value);
                free(new_node);
                return 1;
            }
            else if (strcmp(current->key, key) > 0)
            {
                new_node->next = current;
                new_node->prev = current->prev;

                if (current->prev != NULL)
                    current->prev->next = new_node;
                else
                    ht->array[index] = new_node;

                current->prev = new_node;
                break;
            }

            if (current->next == NULL)
            {
                current->next = new_node;
                new_node->prev = current;
                break;
            }

            current = current->next;
        }
    }

    return 1;
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    unsigned long int index = key_index((const unsigned char *)key, ht->size);
    shash_node_t *current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;

        current = current->next;
    }

    return NULL;
}

void shash_table_print(const
