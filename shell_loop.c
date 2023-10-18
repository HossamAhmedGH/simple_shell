#include "main.h"

/**
 * without_comment - it deletes comments from the input
 *
 * @in: input string
 *
 * Return: input without comments
 */

char *without_comment(char *in)
{
	int i, up_too;

	up_too = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_too = i;
		}
	}

	if (up_too != 0)
	{
		in = _realloc(in, i, up_too + 1);
		in[up_too] = '\0';
	}

	return (in);
}

/**
 * shell_loop - a Loop of hell
 *
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */

void shell_loop(data_shell *datash)
{
	int looooop, i_eof;
	char *input;

	looooop = 1;
	while (looooop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			looooop = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			looooop = 0;
			free(input);
		}
	}
}

