
#include "shell.h"

/**
 * tokenize - tokenizes buffer with delim
 * @buffer: buffer to tokenize
 * @delim: delim
 * Return: pointer to arr of pointers to tokens
 */

char **tokenize(char *buffer, char *delim)
{
	char *token, *bufc;
	int x = 0;
	int w_ct = word_count(buffer);
	char **words = malloc(sizeof(char *) * (w_ct + 1));

	if (!words)
	{
		perror("Error\n");
		exit(-1);
	}
	bufc = _strdup(buffer);
	if (!bufc)
	{
		perror("Strdup error\n");
		return (NULL);
	}
	token = strtok(bufc, delim);

	while (token)
	{
		words[x] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!words[x])
		{
			perror("Malloc error");
			while (x >= 0)
			{
				free(words[x]);
				x--;
			}
			free(words);
			exit(-1);
		}
		_strcpy(words[x], token);
		x++;
		token = strtok(NULL, delim);
	}
	words[x] = NULL;
	free(bufc);
	return (words);
}

/**
 * word_count - find word count
 * @s: pointer to string
 * Return: word count
 */

int word_count(char *s)
{
	int i;
	int words = 1, delim_counter = 1;
	char delim = ' ';

	if (!s)
		return (-1);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == delim)
		{
			if (delim_counter == 0)
			{
				words++;
				delim_counter = 1;
			}
		}
		else
			delim_counter = 0;
	}
	return (words);
}
