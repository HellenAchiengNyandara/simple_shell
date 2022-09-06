
#include "shell.h"

/**
 * make_path - make path for the cell
 *
 * Return: returns the head of the path
 */

path_t *make_path(void)
{
	path_t *head;
	path_t *temp;
	char *path_name, *token;

	path_name = NULL;
	temp = malloc(sizeof(path_t));
	if (!temp)
		exit(-1);

	path_name = _getenv("PATH");

	if (!path_name)
	{
		free(temp);
		return (NULL);
	}
	token = strtok(path_name, ":");

	head = temp;
	while (token)
	{
		temp->dir = _strdup(token);
		token = strtok(NULL, ":");
		if (token)
		{
			temp->next = malloc(sizeof(path_t));
			if (!temp->next)
			{
				free_path(head);
				exit(-1);
			}
			temp = temp->next;
		}
		else
			temp->next = NULL;
	}
	free(path_name);
	return (head);
}

/**
 * free_path - frees the path
 * the path (of the linked list)
 * @head: linked list
 *
 */

void free_path(path_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		free_path(head->next);
	free(head->dir);
	free(head);
}

/**
 * check_path - checks path per set arguments
 * @head: head of PATH linked list
 * @command: argument command
 *
 * Return: path or NULL on failure
 */

char *check_path(path_t *head, char *command)
{
	path_t *temp;
	char *filename;
	struct stat st;

	if (!command || !head)
		return (NULL);

	temp = head;
	while (temp)
	{
		filename = path_concat(temp->dir, command);
		if (!filename)
			return (NULL);
		if (stat(filename, &st) == 0)
		{
			return (filename);
		}
		free(filename);
		temp = temp->next;
	}
	return (NULL);
}
