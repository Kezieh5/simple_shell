#include "shell.h"


/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t o;

	for (o = 0; src[o] != '\0'; o++)
		dest[o] = src[o];
	dest[o] = '\0';
	return (dest);
}

/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t o;

	for (o = 0; o < n && src[o] != '\0'; o++)
		dest[dest_len + o] = src[o];
	dest[dest_len + o] = '\0';

	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *	     which contains a copy of the string given as a parameter
 * @str: string to be copied
 *
 * Return: pointer to duplicated string (success), NULL (fail)
 */
char *_strdup(char *str)
{
	char *cpy, *temp;
	int length = 0;

	if (str == NULL)
		return (NULL);

	for (; str[length]; length++)
		;

	cpy = malloc(sizeof(char) * (length + 1));
	temp = cpy;

	if (cpy == NULL)
		return (NULL);

	while (*str)
		*temp++ = *str++;

	*temp = '\0';

	return (cpy);
}
