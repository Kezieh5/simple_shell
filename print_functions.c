#include "shell.h"

/**
 * pfError - prints error message
 * @argv: pointer to array of arguments
 * @count: pointer to count
 * @first: first token
 * @msg: message to print
 *
 * Return: void
 */
void pfError(char *argv, char *count, char *first, char *msg)
{
	char *colon = ": ";

	print_err(argv);
	print_err(colon);
	print_err(count);
	print_err(colon);
	print_err(first);
	print_err(colon);
	print_err(msg);
}

/**
 * print_err - prints error message
 * @msg: message to print
 *
 * Return: void
 */
void print_err(char *msg)
{
	_puts(STDERR_FILENO, msg);
}

/**
 * _puts - prints a string to a file descriptor
 * @str: string to print
 * @fd: file descriptor
 *
 * Return: void
 */
void _puts(int fd, char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}
