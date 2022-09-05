#include "shell.h"

/**
 * _numlen - find length of number
 * @n: int
 * Return: length
 */
int _numlen(int n)
{
	int len = 1;

	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/**
 * _itoa - take an int and convert to string
 * @num: integer to be converted
 * Return: string
 */

char *_itoa(int num)
{
	char *buffer;
	int len = _numlen(num);
	unsigned int num1;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		exit(-1);

	buffer[len] = '\0';

	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);
	return (buffer);
}
