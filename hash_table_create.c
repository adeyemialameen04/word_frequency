#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *ht = malloc(sizeof(hash_table_t));

	if (ht == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for the hash_table\n");
		return (NULL);
	}

	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for the hash_table array \n");
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ht->array[i] = NULL;
	}

	ht->size = size;

	return (ht);
}
