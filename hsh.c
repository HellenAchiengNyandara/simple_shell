#include "shell.h"
/**
 * main - super simple shell
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{


	if (!argc)
		return (0);
	prompt(argv[0]);
	return (0);
}
