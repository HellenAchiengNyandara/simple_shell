#include "shell.h"
/**
 * _environ - builds an environment linked list
 *
 * Return: returns a pointer to the head of the linked list
 */
path_t *_environ(void)
{
	path_t *head;
	path_t *temp;
	int x = 0;

	head = malloc(sizeof(path_t));
	if (!head)
		exit(-1);
	temp = head;
	while (environ[x])
	{
		temp->dir = _strdup(environ[x]);
		if (environ[x + 1] != NULL)
		{
			temp->next = malloc(sizeof(path_t));
			if (!temp->next)
				exit(-1);
			temp = temp->next;
		}
		x++;
	}
	temp->next = NULL;
	return (head);
}
