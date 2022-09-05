#include "shell.h"
/**
 * prompt - shell loop
 * @program: name of shell
 *
 */

void prompt(char *program)
{
	char *line;
	char **args;
	int x, status, line_num = 0;

	env = _environ();
	main_path = make_path();
	status = 1;
	signal(SIGINT, signal_handler);


	while (status)
	{
		line_num++;
		line = read_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		args = tokenize(line, DELIM);
		if (check_builtin(args, line) == 1)
			status = execute(args, program, line_num);
		x = 0;
		while (args[x] != NULL)
		{
			if (args[x])
				free(args[x]);
			x++;
		}

		if (line)
			free(line);
		if (args)
			free(args);
	}
	free(args), free(line);
	free_path(main_path);
	free_path(env);
}


/**
 * prompter - function to print prompt
 *
 * Description: print prompt
 * Return: na
 */
void prompter(void)
{
	write(1, "$ ", 2);
}

/**
 * clear_screen - clears the screen
 * Return: 0
 */

char clear_screen(void)
{
	write(1, "\033[H\033[J", 7);
	return (0);
}

/**
 * read_line - gets command line from user
 *
 * Return: returns the user input from the command line
 */
char *read_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;

	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
	if (getline(&buf, &bufsize, stdin) <= 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		hsh_exit(NULL, buf);
	}
	return (buf);
}
