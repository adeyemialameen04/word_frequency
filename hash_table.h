#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

typedef struct hash_node_s
{
	char *word;
	int frequency;
	struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
	unsigned long int size;
	unsigned long int capacity;
	hash_node_t **array;
} hash_table_t;

int hash_table_set(hash_table_t *ht, char *word, int frequency);
hash_table_t *hash_table_create(unsigned long int size);
void hash_table_print(hash_table_t *ht);

#endif /* _HASH_TABLE_H_ */
