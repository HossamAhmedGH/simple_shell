#include "main.h"

/**
 * rev_string - it reverses a string.
 * @s: an input string.
 * Return: no return.
 */

void rev_string(char *s)
{
	int count = 0, f, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (f = 0; f < (count - 1); f++)
	{
		for (j = f + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

