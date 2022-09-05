#include "shell.h"
/**
 * main - The simple shell program
 * @argc: number of arguments
 * @argv: array count of arguments
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
