#include "main.h"
/**
 * _memset - function that fills memory with a constant byte
 * @s: is the direction you are going
 * @b: constant character variable
 * @n: is the limit to which you will reach
 * Return: s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}
