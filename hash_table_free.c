#include <stdlib.h>
#include "hash_table.h"

void hash_table_free(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *curr, *next;

	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		while (curr != NULL)
		{
			next = curr->next;
			free(curr->word);
			free(curr);
			curr = next;
		}
	}

	free(ht->array);
	free(ht);
}
