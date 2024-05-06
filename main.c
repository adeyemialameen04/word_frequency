#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *content = NULL, *copy;
	hash_table_t *ht;

	if (argc < 2 || argc > 2)
	{
		printf("Usage %s filename.txt\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	content = save_to_buffer_from_file(argv[1]);
	if (content == NULL)
	{
		fprintf(stderr, "Reading to string failed\n");
		return (1);
	}
	
	ht = hash_table_create(10);
	copy = strdup(content);
	char *token = strtok(copy, " \t\n.,?!;:\"");

	while (token != NULL)
	{
		hash_table_set(ht, token);
		token = strtok(NULL, " \t\n.,?!;:\"");
	}
	
	hash_table_print(ht);
	free(content);
	free(copy);

	return (0);
}
