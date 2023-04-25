#include "shell.h"

int _abs(int n);
void rev_string(char *s);

/**
 * itoa - converts an integer to a string
 * @num: integer to convert
 * @str: pointer to string
 * @base: base of the number
 *
 * Return: string of the integer
 */
char *itoa(int num, char *str, int base)
{
	unsigned int n = _abs(num), i = 0, r;

	if (base < 2 || base > 32)
		return (str);

	while (n)
	{
		r = n % base;
		if (r >= 10)
			str[i++] = 65 + (r - 10);
		else
			str[i++] = 48 + r;
		n /= base;
	}

	if (i == 0)
		str[i++] = '0';

	if (num < 0 && base == 10)
		str[i++] = '-';

	str[i] = '\0';
	rev_string(str);
	return (str);
}

/**
 * _abs - returns the absolute value of an integer
 * @n: integer to check
 *
 * Return: absolute value of n
 */
int _abs(int n)
{
	return (n < 0 ? -n : n);
}

/**
 * rev_string - reverses a string
 * @s: string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length, i, j;
	char temp;

	for (length = 0; s[length] != '\0'; length++)
		;

	j = length - 1;

	for (i = 0; i < length / 2; i++)
	{
		temp = s[i];
		s[i] = s[j];
		s[j--] = temp;
	}
}
