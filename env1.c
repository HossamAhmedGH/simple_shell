#include "main.h"

/**
 * cmp_env_name - it compares env variables names
 * with the name passed.
 * @nenv: the name of the environment variable
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are.
 */

int cmp_env_name(const char *nenv, const char *name)
{
	int a;

	for (a = 0; nenv[a] != '='; a++)
	{
		if (nenv[a] != name[a])
		{
			return (0);
		}
	}

	return (a + 1);
}

/**
 * _getenv - it does get an environment variable
 * @name: the name of the environment variable
 * @_environ: environment variable
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, move;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	move = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		move = cmp_env_name(_environ[i], name);
		if (move)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + move);
}

/**
 * _env - it prints the evironment variables
 *
 * @datash: a  data relevant.
 * Return: 1 on success.
 */

int _env(data_shell *datash)
{
	int f, j;

	for (f = 0; datash->_environ[f]; f++)
	{

		for (j = 0; datash->_environ[f][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[f], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}

