#include "main.h"

/**
 * get_len - it does Get the longht of a number.
 * @n: type int number.
 * Return: the Lenght of a number.
 */

int get_len(int n)
{
	unsigned int n1;
	int longht = 1;

	if (n < 0)
	{
		longht++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		longht++;
		n1 = n1 / 10;
	}

	return (longht);
}

/**
 * aux_itoa - a function converts int to string.
 * @n: a type int number
 * Return: a String.
 */

char *aux_itoa(int n)
{
	unsigned int n1;
	int longht = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (longht + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + longht) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	longht--;
	do {
		*(buffer + longht) = (n1 % 10) + '0';
		n1 = n1 / 10;
		longht--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, z = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				z *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * z);
		z /= 10;
	}
	return (oi * pn);
}

