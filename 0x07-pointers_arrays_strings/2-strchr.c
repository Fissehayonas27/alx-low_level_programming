#include "main.h"
#include <stdio.h>
/**
 * _strchr -  function that locates a character in a string
 * @s: is a pointer which stores the addresses
 * @c: is the constant variable that receives
 * Return: (s + i).
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; *(s + i) != '\0' ; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return (NULL);
}
