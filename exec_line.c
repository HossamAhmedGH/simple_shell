#include "main.h"

/**
 * exec_line - it finds builtins and commands
 *
 * @datash: a data relevant (args)
 * Return: 1 on success.
 *
 */

int exec_line(data_shell *datash)
{
	int (*builtininin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtininin = get_builtin(datash->args[0]);

	if (builtininin != NULL)
		return (builtininin(datash));

	return (cmd_exec(datash));
}

