#include "main.h"

/**
 * set_string - function that sets the value of a pointer to a char.
 * @s: is the double pointer
 * @to: is the pointer to which it points
 */
void set_string(char **s, char *to)
{
	*s = to;
}
