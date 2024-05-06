#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

char *save_to_buffer_from_file(char *filename)
{
	char *buffer = 0;
	long size;
	FILE *fd = fopen(filename, "rb");

	if (fd == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		return (NULL);
	}

	fseek(fd, 0, SEEK_END);
	size = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	buffer = malloc(size + 1);
	if (!buffer)
	{
		fprintf(stderr, "Unable to allocate memory for buffer\n");
		fclose(fd);
		return (NULL);
	}

	fread(buffer, 1, size, fd);
	buffer[size] = '\0';

	fclose(fd);

	return (buffer);
}
