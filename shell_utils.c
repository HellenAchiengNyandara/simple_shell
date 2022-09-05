#include "shell.h"

/**
 * check_command - checks if command is valid
 * @args: argument vector
 * @program: name of shell
 * @n: line count
 * Return: returns something
 */

int check_command(char **args, char *program, int n)
{
	char *result;
	int line_num = n;

	if (args[0][0] == '.' || args[0][0] == '/')
	{
		if (execve(args[0], args, environ) == -1)
			__error(args, program, 3, line_num);
	}
	else
	{
		result = (check_path(main_path, args[0]));
		if (!result)
			__error(args, program, 1, line_num);
		if (execve(result, args, environ) == -1)
			__error(args, program, 2, line_num);
	}
	return (1);
}

/**
 * execute - executes a program
 * @args: a double pointer of command line arguments
 * @program: name of shell
 * @n: line count
 * Return: always returns 1
 */

int execute(char **args, char *program, int n)
{
	pid_t child_pid;
	int status, line_num = n;

	child_pid = fork();
	if (child_pid == 0)
	{
		check_command(args, program, line_num);
		exit(0);
	}
	else if (child_pid == -1)
	{
		perror("Error: fork failed");
		exit(99);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (1);

}

/**
 * signal_handler - handles sigint
 *
 *
 *@sig: signal
 */

void signal_handler (int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		prompter();
	}
}
