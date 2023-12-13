#include "main.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * read_interactive_command - handles interactive commands
 * @path_toke: an array of path dirs
 * @buffer: buffer to read the command into
 * @argv: the name of the program
 * Return: Nothing
*/

char *read_interactive_command(char *path_toke[], char *buffer, char *argv)
{
	int i;

	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;
	char *cp;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		bytes_read = getline(&buffer, &buffer_size, stdin);
		cp = buffer;

		if (bytes_read == -1)
		{
			printf("an error occurred.\n");
			continue; /* This is the EOF condition */
		}

		for (i = 0; buffer[i] == ' '; i = 0)
			buffer += 1; /* Trims user input at beginning */

		if (buffer[0] == '\n')
			continue; /* hitting enter restarts the loop */

		if (starts_with("exit", buffer) == 0)
		{
			exit(errno);
			break;
		}
		if (starts_with("env", buffer) == 0)
		{
			_printenv();
			fflush(stdin);
			continue;
		}
		parse_command(buffer, path_toke, argv);
	}

	return (cp);
}

/**
 * read_non_interactive_command - handles non_interactive commands
 * @path: an array of path dirs
 * @buffer: buffer to read the command into
 * @argv: the name of the program
 * Return: Nothing
*/

char *read_non_interactive_command(char *path[], char *buffer, char *argv)
{
	int i;

	ssize_t bytes_read = 0;
	size_t buffer_size = BUFFER_SIZE;
	char *cp;

	while (bytes_read != -1)
	{
		bytes_read = getline(&buffer, &buffer_size, stdin);
		cp = buffer;

		if (bytes_read == -1)
		{
			continue; /* This is the EOF condition */
		}

		for (i = 0; buffer[i] == ' '; i = 0)
			buffer += 1; /* if command starts with spaces, disregard them */

		if (buffer[0] == '\n')
			continue; /* if the file encounters a linebreak, read next */

		if (starts_with("exit", buffer) == 0)
			break;

		parse_command(buffer, path, argv);

	}

	return (cp);
}
/**
 * _printenv - a function to print the environment variable
 */
void _printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
