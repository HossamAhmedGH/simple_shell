#include "main.h"

/**
 * _memcpy - it copies information between void pointers.
 * @newptr: the destination pointer.
 * @ptr: the source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int l;

	for (l = 0; l < size; l++)
		char_newptr[l] = char_ptr[l];
}

/**
 * _realloc - it reallocates a memory block.
 * @ptr: a pointer to the memory previously allocated.
 * @old_size: the size, in bytes, of the allocated space of ptr.
 * @new_size: the new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, it returns ptr without changes.
 * if malloc fails, returns NULL.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - it reallocates a memory block of a double pointer.
 * @ptr: a double pointer to the memory previously allocated.
 * @old_size: the size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int l;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (l = 0; l < old_size; l++)
		newptr[l] = ptr[l];

	free(ptr);

	return (newptr);
}

