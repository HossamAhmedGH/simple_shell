#include "main.h"

/**
 * read_line - it reads the input string.
 *
 * @i_eof: return value of getline function
 *
 * Return: an input string
 */

char *read_line(int *i_eof)
{
	char *inpot = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&inpot, &bufsize, stdin);

	return (inpot);
}

