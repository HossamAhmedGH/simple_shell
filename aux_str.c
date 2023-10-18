#include "main.h"

/**
 * _strcat - cats two strings
 * @dest: a char pointer the dest of the copied str
 * @src: a const char pointer the source of str
 * Return: the dest
 */

char *_strcat(char *dest, const char *src)
{
	int f;
	int j;

	for (f = 0; dest[f] != '\0'; f++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[f] = src[j];
		f++;
	}

	dest[f] = '\0';
	return (dest);
}

/**
 * *_strcpy - Cpies the string pointed to by src.
 * @dest: the Type char pointer the dest of the copied str
 * @src: the Type char pointer the source of str
 * Return: the dest.
 */

char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - a Function that compares two strings.
 * @s1: a type str compared
 * @s2: a type str compared
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int f;

	for (f = 0; s1[f] == s2[f] && s1[f]; f++)
		;

	if (s1[f] > s2[f])
		return (1);
	if (s1[f] < s2[f])
		return (-1);
	return (0);
}

/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */

char *_strchr(char *s, char c)
{
	unsigned int f = 0;

	for (; *(s + f) != '\0'; f++)
		if (*(s + f) == c)
			return (s + f);
	if (*(s + f) == c)
		return (s + f);
	return ('\0');
}

/**
 * _strspn - it gets the length of a prefix substring.
 * @s: the initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int f, j, bool;

	for (f = 0; *(s + f) != '\0'; f++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + f) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (f);
}

