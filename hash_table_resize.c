#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

void hash_table_resize(hash_table_t *ht, unsigned long int new_size)
{
	unsigned long int i;
	hash_node_t *curr, *next;
	hash_table_t *new_ht = hash_table_create(new_size);

	if (new_ht == NULL) {
		fprintf(stderr, "Unable to allocate memory for the resized hash_table array\n");
		exit(EXIT_FAILURE);
	}

	// Rehash all existing elements into the new larger table
	for (i = 0; i < ht->size; i++) {
		curr = ht->array[i];

		while (curr != NULL) {
			next = curr->next;
			hash_table_set(new_ht, curr->word);
			curr = next;
		}
	}

	for (i = 0; i < ht->size; i++) {
		curr = ht->array[i];
		while (curr != NULL) {
			next = curr->next;
			free(curr->word);
			free(curr);
			curr = next;
		}
	}

	free(ht->array);
	ht->size = new_ht->size;
	ht->count = new_ht->count;
	ht->array = new_ht->array;
	free(new_ht);
}
