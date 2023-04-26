#include "shell.h"

#define MAX_WORDS 100
/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @delim: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *delim)
{
    int a, b, c;
    char **words;

    if (str == NULL || strlen(str) == 0)
        return NULL;

    if (!delim || strlen(delim) == 0)
        delim = " ";

    words = malloc(MAX_WORDS * sizeof(char *));
    if (!words)
        return NULL;

    a = b = c = 0;
    while (str[a] != '\0' && b < MAX_WORDS - 1) {
        while (isspace(str[a]))
            a++;

        c = a;
        while (str[c] != '\0' && !isspace(str[c]) && !strstr(delim, &str[c]))
            c++;

        words[b] = malloc(c - a + 1);
        if (!words[b])
            break;

        strncpy(words[b], &str[a], c - a);
        words[b][c - a] = '\0';

        b++;
        a = c;
    }

    if (b == 0) {
        free(words);
        return NULL;
    }

    words[b] = NULL;

    return words;
}
/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow3(char *str, char d)
{
	int a, b, c, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);

	/* Count the number of words*/
	for (a = 0; str[a]; a++)
		if (str[a] != d && (a == 0 || str[a - 1] == d))
			numwords++;

	if (numwords == 0)
		return (NULL);

	/* Allocate memory for the array of strings*/
	s = malloc((numwords + 1) * sizeof(char *));
	if (!s)
		return (NULL);

	/* Populate the array of strings*/
	for (a = 0, b = 0; b < numwords; b++)
	{
		/* Skip delimiters*/
		while (str[a] == d)
			a++;

		/* Count the length of the current word*/
		c = 0;
		while (str[a + c] != d && str[a + c])
			c++;

		/* Allocate memory for the current word*/
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			/* Free memory for previously allocated words*/
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}

		/* Copy the current word into the array of strings*/
		for (c = 0; str[a] != d && str[a]; a++, c++)
			s[b][c] = str[a];
		s[b][c] = '\0';
	}

	/* Null-terminate the array of strings*/
	s[numwords] = NULL;

	return (s);
}
