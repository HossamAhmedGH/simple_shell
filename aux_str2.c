#include "main.h"

/**
 * _strdup - it duplicates a str in the heap memory.
 * @s: a Type char pointer str
 * Return: duplicated str
 */

char *_strdup(const char *s)
{
	char *neow;
	size_t len;

	len = _strlen(s);
	neow = malloc(sizeof(char) * (len + 1));
	if (neow == NULL)
		return (NULL);
	_memcpy(neow, s, len + 1);
	return (neow);
}

/**
 * _strlen - it Returns the lenght of a string.
 * @s: a Type char pointer
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - it does compare chars of strings
 * @str: an input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int f, j, k;

	for (f = 0, k = 0; str[f]; f++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[f] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (f == k)
		return (1);
	return (0);
}

/**
 * _strtok - it splits a string by some delimiter.
 * @str: the input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */

char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - it defines if string passed is a number
 *
 * @s: an input string
 * Return: 1 if string is a number. 0 in other case.
 */

int _isdigit(const char *s)
{
	unsigned int d;

	for (d = 0; s[d]; d++)
	{
		if (s[d] < 48 || s[d] > 57)
			return (0);
	}
	return (1);
}

