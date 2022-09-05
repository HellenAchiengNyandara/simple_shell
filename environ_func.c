
#include "shell.h"
/**
 * _getenv - searches environment list for variable names available
 * @name: variable name
 * Description: function to pass environment to the program
 * Return: pointer
 */
char *_getenv(char *name)
{
	unsigned int y;
	char *match, *copy;
	path_t *temp;

	match = NULL;
	temp = env;

	while (temp)
	{
		y = 0;
		while (name[y])
		{
			if (name[y] != temp->dir[y])
				break;
			if (name[y + 1] == '\0' && temp->dir[y + 1] == '=')
				match = temp->dir;
			y++;
		}
		if (match)
			break;
		temp = temp->next;
	}

	copy = malloc(sizeof(char *) * (_strlen(match)));
	if (!copy)
		exit(-1);
	_strcpy(copy, match);


	return (copy);
}
