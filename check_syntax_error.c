#include "main.h"

/**
 * repeated_char - it counts the repetitions of a char
 *
 * @input: the input string
 * @i: index
 * Return: repetitions
 */

int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, i + 1));

	return (i);
}

/**
 * error_sep_op - finds syntax errors
 * @input: the input string
 * @i: index
 * @last: last char read
 * Return: the index of the error. 0 when there are no
 * errors
 */

int error_sep_op(char *input, int i, char last)
{
	int counter;

	counter = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			counter = repeated_char(input, 0);
			if (counter == 0 || counter > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			counter = repeated_char(input, 0);
			if (counter == 0 || counter > 1)
				return (i);
		}
	}

	return (error_sep_op(input + 1, i + 1, *input));
}

/**
 * first_char - it finds index of the first char
 *
 * @input: the input string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */

int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - it prints when a syntax error is found
 * @datash: the data structure
 * @input: an input string
 * @i: index of the error
 * @bool: to control msg error
 * Return: no return
 */

void print_syntax_error(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *count;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	count = aux_itoa(datash->count);
	length = _strlen(datash->av[0]) + _strlen(count);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(count);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, count);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(count);
}

/**
 * check_syntax_error - an intermediate function to
 * find and print a syntax error
 * @datash: the data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */

int check_syntax_error(data_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0;
	int r = 0;

	f_char = first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, begin, 0);
		return (1);
	}

	r = error_sep_op(input + begin, 0, *(input + begin));
	if (r != 0)
	{
		print_syntax_error(datash, input, begin + r, 1);
		return (1);
	}

	return (0);
}
