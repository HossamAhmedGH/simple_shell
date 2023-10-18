#include "main.h"

/**
 * exit_shell - it exits the shell
 *
 * @datash: a data relevant (status and args)
 *
 * Return: 0 on success.
 */

int exit_shell(data_shell *datash)
{
	unsigned int uistatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datash->args[1] != NULL)
	{
		uistatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_number = uistatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (uistatus % 256);
	}
	return (0);
}

