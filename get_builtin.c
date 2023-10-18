#include "main.h"

/**
 * get_builtin - the builtin that pais the command in the arg
 * @cmd: a command
 * Return: function pointer of the builtin command
 */

int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int b;

	for (b = 0; builtin[b].name; b++)
	{
		if (_strcmp(builtin[b].name, cmd) == 0)
			break;
	}

	return (builtin[b].f);
}

