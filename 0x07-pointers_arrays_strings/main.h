/* This file contains all the prototypes of the projects */

/* t0. _memset - function that fills memory with a constant byte. */
char *_memset(char *s, char b, unsigned int n);
/* t1. _memcpy - function that copies memory area.*/
char *_memcpy(char *dest, char *src, unsigned int n);
/* t2. _strchr - function that locates a character in a string. */
char *_strchr(char *s, char c);
/* t3. _strspn - function that gets the length of a prefix substring. */
unsigned int _strspn(char *s, char *accept);
/* t4. _strpbrk - function that searches a string for any of a set of bytes. */
char *_strpbrk(char *s, char *accept);
/* t5. _strstr - function that locates a substring. */
char *_strstr(char *haystack, char *needle);
/* t6. print_chessboard - function that prints the chessboard. */
void print_chessboard(char (*a)[8]);
/* t7. print_diagsums - unction that prints the sum of the two diagonals of a square matrix of integers. */
void print_diagsums(int *a, int size);
/* t8. set_string -  function that sets the value of a pointer to a char. */
void set_string(char **s, char *to);
/* _putchar */
int _putchar(char c);
