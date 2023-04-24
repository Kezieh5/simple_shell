#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * _getchar - reads a character from stdin
 *
 * Return: int representing the character read
 */
int _getchar(void)
{
	int rd;
	char buffer[2];

	rd = read(STDIN_FILENO, buffer, 1);

	if (rd == -1)
		exit(99);

	if (rd == 0)
		return (EOF);

	return (*buffer);
}

/**
 * _getline - reads a line from stdin
 * @lineptr: pointer to a string
 * @n: size of the string
 * @stream: file descriptor
 *
 * Return: int representing the number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	char *buffer;
	size_t alloc = 120, init_size = 0, old_size, new_size;
	static int i; /* TODO: Use static variable */

	(void)i;
	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*lineptr = malloc(alloc);
		if (*lineptr == NULL)
			return (-1);
		*n = alloc;
	}
	while ((c = _getchar()) != EOF)
	{
		if (init_size >= *n)
		{
			old_size = alloc; /* Save the old size allocated */
			new_size = *n + alloc;
			buffer = _realloc(*lineptr, old_size, new_size + 1); /* TODO: n_alloc */

			if (buffer == NULL)
				return (-1);

			alloc = new_size + 1; /* Update the size allocated with the new size*/
			*lineptr = buffer;
			*n = new_size;
		}
		init_size++;
		(*lineptr)[init_size - 1] = (char)c;

		if (c == '\n')
			break;
	}
	if (c == EOF)
		return (-1);
	(*lineptr)[init_size] = '\0';
	return ((ssize_t)init_size);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: new size in bytes of the new memory block
 *
 * Return: pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *new_ptr, *old_ptr = ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		new_ptr[i] = old_ptr[i];

	free(ptr);
	return (new_ptr);
}
