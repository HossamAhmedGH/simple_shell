#include "main.h"

/**
 * aux_help - a Help information for the builtin help.
 * Return: no return
 */

void aux_help(void)
{
	char *hlp = "hlp: hlp [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * aux_help_alias - a Help information for the builtin alias.
 * Return: no return
 */

void aux_help_alias(void)
{
	char *hlp = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

/**
 * aux_help_cd - a Help information for the builtin alias.
 * Return: no return
 */

void aux_help_cd(void)
{
	char *hlp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, hlp, _strlen(hlp));
	hlp = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hlp, _strlen(hlp));
}

