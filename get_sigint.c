#include "main.h"

/**
 * get_sigint - it does Handle the crtl + c call in prompt
 *
 * @sig: a Signal handler
 */

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

