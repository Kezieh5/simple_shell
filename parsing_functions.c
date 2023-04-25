#include "shell.h"

/**
 * add_path - adds the PATH environment variable to the linked list
 * @tokens: pointer to array of tokens
 *  @path: pointer to the linked list
 *
 * Return: pointer to the path
 */
char *add_path(char ***tokens, list_t *path)
{
	struct stat st;
	char *first, *cpy_path = NULL;
	list_t *head;
	int first_len, second_len;

	if (*tokens == NULL)
		return (NULL);

	head = path;
	if (head == NULL)
		return (NULL);

	first = *(tokens)[0];
	first_len = _strlen(first);

	while (head != NULL)
	{
		second_len = _strlen(head->str);
		cpy_path = malloc((second_len + first_len + 2) * sizeof(char));
		if (cpy_path == NULL)
			return (NULL);
		*cpy_path = '\0';
		_strcat(cpy_path, head->str);
		_strcat(cpy_path, "/");
		_strcat(cpy_path, first);
		if (stat(cpy_path, &st) == 0)
			break;

		free(cpy_path);
		cpy_path = NULL;
		head = head->next;
	}
	return (cpy_path);
}

/**
 * process_tokens - gets all strings separated by a delimiter
 * @tokens: pointer to array of tokens
 * @buffer: pointer to buffer
 * @count_token: number of tokens
 *
 * Return: void
 */
void process_tokens(char ***tokens, char **buffer, int count_token)
{
	char *token = NULL, *delim = " \n\t";
	int i;

	*tokens = malloc(sizeof(char *) * count_token);
	if (*tokens == NULL)
		perror("Error: ");
	token = strtok(*buffer, delim);
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, delim);
	}
	(*tokens)[i] = token; /*Save the NULL token*/
}

/**
 * tokens_len - gets the number of words separated by a delimiter
 * @read_len: number of characters read
 * @buffer: pointer to buffer
 *
 * Return: number of tokens
 */
int tokens_len(ssize_t read_len, char **buffer)
{
	char *tmp = NULL, *cpy_buffer = NULL, *delim = " \n\t";
	int i;

	cpy_buffer = malloc(sizeof(char) * read_len);
	if (cpy_buffer == NULL)
		perror("Error: ");
	_strcpy(cpy_buffer, *buffer);
	tmp = strtok(cpy_buffer, delim);
	for (i = 0; tmp != NULL; i++)
		tmp = strtok(NULL, delim);
	i++; /* One more to save NULL */
	free(cpy_buffer);
	return (i);
}

/**
 * nl_replace - replaces the newline character with a null character
 * @buffer: pointer to buffer
 *
 * Return: void
 */
void nl_replace(char **buffer)
{
	int i;

	for (i = 0; (*buffer)[i] != '\0'; i++)
		continue;
	(*buffer)[i - 1] = '\0';
}

/**
 * _readline - reads a line from stdin
 * @buffer: pointer to buffer
 * @tokens: pointer to array of tokens
 *
 * Return: number of characters read
 */
ssize_t _readline(char **buffer, char ***tokens)
{
	size_t buffer_size = 0;
	ssize_t read;
	int count_token, i;

	*tokens = NULL;
	read = _getline(buffer, &buffer_size, stdin);

	if (read > 0)
	{
		i = 0;
		while ((*buffer)[i] == ' ' || (*buffer)[i] == '\t')
		{
			if ((*buffer)[i + 1] == '\n')
				return (read);
			i++;
		}
	}

	if (read > 0 && **buffer != '\n')
	{
		nl_replace(buffer);
		count_token = tokens_len(read, buffer);
		process_tokens(tokens, buffer, count_token);
		shell_exit(tokens, count_token, &read);
		_env(tokens, count_token);
	}

	return (read);
}
