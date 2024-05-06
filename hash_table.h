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
	hash_node_t **array;
} hash_table_t;

unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, char *word);
hash_table_t *hash_table_create(unsigned long int size);
void hash_table_print(hash_table_t *ht);
char *save_to_buffer(char *filename);
char *save_to_buffer_from_file(char *filename);

#endif /* _HASH_TABLE_H_ */
