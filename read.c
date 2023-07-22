#include "main.h"

/**
 * read_command - Read the command
 * Return: 0 Success
 */

void read_command(char *command)
{
	ssize_t bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

	if (bytes_read == -1)
	{
		perror("Read error");
		exit(EXIT_FAILURE);
	}
	else if (bytes_read == 0)
	{
		/* Handle end of file (Ctrl+D) */
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	/* Remove the trailing newline character */
	command[bytes_read - 1] = '\0';
}
