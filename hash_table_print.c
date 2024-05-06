#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

void hash_table_print(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *curr;
	int is_first = 1;

	if (ht == NULL)
	{
		fprintf(stderr, "Can't print an empty hash table\n");
		return;
	}

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];

		while (curr != NULL)
		{
			if (is_first)
				is_first = 0;
			else
				printf(", ");


			printf("'%s': %d", curr->word, curr->frequency);
			curr = curr->next;
		}
	}
	printf("}\n");
}
