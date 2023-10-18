#include "main.h"

/**
 * swap_char - it swaps | and & for non-printed chars
 *
 * @input: input string
 * @bool: type of swap
 *
 * Return: swapped string
 */

char *swap_char(char *input, int bool)
{
	int f;

	if (bool == 0)
	{
		for (f = 0; input[f]; f++)
		{
			if (input[f] == '|')
			{
				if (input[f + 1] != '|')
					input[f] = 16;
				else
					f++;
			}

			if (input[f] == '&')
			{
				if (input[f + 1] != '&')
					input[f] = 12;
				else
					f++;
			}
		}
	}
	else
	{
		for (f = 0; input[f]; f++)
		{
			input[f] = (input[f] == 16 ? '|' : input[f]);
			input[f] = (input[f] == 12 ? '&' : input[f]);
		}
	}
	return (input);
}

/**
 * add_nodes - it does add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 *
 * @input: an input string
 * Return: no return
 */

void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	int i;
	char *linee;

	input = swap_char(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_sep_node_end(head_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			add_sep_node_end(head_s, input[i]);
			i++;
		}
	}

	linee = _strtok(input, ";|&");
	do {
		linee = swap_char(linee, 1);
		add_line_node_end(head_l, linee);
		linee = _strtok(NULL, ";|&");
	} while (linee != NULL);

}

/**
 * go_next - it does go to the next command line stored
 *
 * @list_s: separator list
 * @list_l: a command line list
 *
 * @datash: data structure
 * Return: no return
 */

void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_separator;
	sep_list *ls_s;
	line_list *ls_l;

	loop_separator = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_separator)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_separator = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_separator = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_separator)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - it splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @datash: a  data structure
 *
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */

int split_commands(data_shell *datash, char *input)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int luup;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		luup = exec_line(datash);
		free(datash->args);

		if (luup == 0)
			break;

		go_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (luup == 0)
		return (0);
	return (1);
}

/**
 * split_line - it tokenizes the input string
 *
 * @input: input string.
 *
 * Return: a string splitted.
 */

char **split_line(char *input)
{
	size_t bsize;
	size_t i;
	char **tokenzz;
	char *token;

	bsize = TOK_BUFSIZE;
	tokenzz = malloc(sizeof(char *) * (bsize));
	if (tokenzz == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokenzz[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokenzz = _reallocdp(tokenzz, i, sizeof(char *) * bsize);
			if (tokenzz == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokenzz[i] = token;
	}

	return (tokenzz);
}

