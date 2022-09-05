
#include "shell.h"
/**
 * _strcpy - copies string from one pointer to a new pointer
 * @dest: destination pointer for the copied string
 * @src: origin pointer of the copied string
 *
 * Return: pointer to string destination
 */

char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while (*src)
	{
		*dest  = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

/**
 * _strlen - function to return string length
 * @s: string
 *
 * Return: length of the string
 */

int _strlen(char *s)
{
	int x = 0;

	while (s[x] != '\0')
		x++;
	return (x);
}

/**
 * _strdup - returns a pointer to newly allocated space in memory
 * @str: string to copy
 *
 * Return: returns a pointer to the copied string
 */

char *_strdup(char *str)
{
	int x;
	char *s;

	if (str == NULL)
		return (NULL);

	s = malloc(sizeof(char) * (_strlen(str) + 1));
	if (s == NULL)
		exit(-1);
	for (x = 0; str[x] != '\0'; x++)
		s[x] = str[x];
	s[x] = '\0';
	return (s);
}

#include "shell.h"

/**
 * _strcmp - compares 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: Returns 0 if strings are same size. Positive difference if
 * s1 is greater than s2. Negative difference if s1 is smaller than s2.
 */

int _strcmp(char *s1, char *s2)
{
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while ((*s1 == *s2) && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else
		return ((int)(*s1 - *s2));
}

/**
 * path_concat - concatenates directories and command
 * @s1: first string
 * @s2: second string
 *
 * Return: returns a pointer to the concatenated string
 */

char *path_concat(char *s1, char *s2)
{
	int x, y;
	char *s;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 2));
	if (s == NULL)
		exit(-1);

	for (x = 0; s1[x]; x++)
		s[x] = s1[x];
	s[x] = '/';
	x++;
	for (y = 0; s2[y]; y++)
		s[x + y] = s2[y];
	s[x + y] = '\0';
	return (s);
}
