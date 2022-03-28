#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - function that sets the value of a pointer to a char.
 * @a: pointer int
 * @size: int size
 *
 * Return: Always 0.
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	int vd1 = 0, vd2 = 0, limit = 1;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				vd1 += *(a + ((i * size) + j));
			}
			if ((size - limit) == j)
			{
				vd2 += *(a + ((i * size) + j));
				limit++;
			}
		}
	}
	printf("%d, %d\n", vd1, vd2);
}
