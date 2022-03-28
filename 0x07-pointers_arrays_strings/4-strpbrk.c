#include "main.h"
#include <stdio.h>

/**
 * _includes - function that validates if the string is in the characters
 * @str: pointer to validate.
 * @c: char to count
 * Return: 0.
 */
int _includes(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str += 1;
	}
	return (0);
}

/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * @s: is the pointer
 * @accept: it is the validation that accepts
 * Return: count.
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i;

	for (i = 0; *(s + i) != '\0'; i++)
		if (_includes(accept, *(s + i)))
			return (s  + i);
	return (NULL);
}
