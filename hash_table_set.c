#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define LOAD_FACTOR_THRESHOLD 0.7

hash_node_t *create_pair(char *word)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for a new node\n");
		return (NULL);
	}

	new_node->word = strdup(word);
	if (new_node->word == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for a word in new node\n");
		free(new_node);
		return (NULL);
	}

	new_node->frequency = 1;
	new_node->next = NULL;
	return (new_node);
}

int hash_table_set(hash_table_t *ht, char *word)
{
	hash_node_t *curr, *new_node;
	unsigned long int idx;

	if (ht == NULL || *word == '\0')
	{
		return (0);
	}

	idx = key_index((const unsigned char *)word, ht->size);
	curr = ht->array[idx];
	while (curr != NULL)
	{
		if (strcmp(curr->word, word) == 0)
		{
			curr->frequency++;
			return (1);
		}
		curr = curr->next;
	}

	new_node = create_pair(word);
	if (new_node == NULL)
	{
		fprintf(stderr, "Unable to create new node\n");
		return (0);
	}
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;
	ht->count++;
	
	if ((double)ht->count / ht->size >= LOAD_FACTOR_THRESHOLD)
	{
		hash_table_resize(ht, ht->size * 2);
		printf("Resizing happened here\n");
	}

	return (1);
}
