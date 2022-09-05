#include "shell.h"
/**
 * __error - handle all error
 * @args: arguments passed in
 * @cmd: command
 * @code: error code
 * @n: line count
 */
void __error(char **args, char *cmd, int code, int n)
{
	char *str_num = NULL;
	int line_num = n;

	str_num = _itoa(line_num);
	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, str_num, _strlen(str_num));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, args[0], _strlen(args[0]));
	free(str_num);
	free_path(main_path);
	free_path(env);
	free(args);


	if (code == 1)
	{
		write(STDERR_FILENO, ": not found\n", 12);
		exit(127);
	}
	if (code == 2)
	{
		write(STDERR_FILENO, ": command not found\n", 21);
		exit(0);
	}
	if (code == 3)
	{
		write(STDERR_FILENO, ": Permission denied\n", 21);
		exit(0);
	}

}
