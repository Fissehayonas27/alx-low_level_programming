#include "main.h"
#include <stdio.h>
/**
 * _strstr - function that locates a substring.
 * @haystack: char hello, world
 * @needle: char world
 * Return: Always 0.
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0;

	while (haystack[i] != '\0')
	{
		while (*(haystack +  i) != '\0' && *(needle +  i) != '\0'
				&& haystack[i] == needle[i])
		{
			i++;
		}
		if (needle[i] == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return ('\0');
}
