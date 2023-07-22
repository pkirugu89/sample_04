#include "main.h"

/**
 * display_prompt - displays the shell input.
 * run_shell - runs the shell.
 * Return: 0 success
 */

extern char **environ;

void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

void run_shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_COMMAND_LENGTH];
	int argc;
	char *token;

	while (1)
	{
		/* Display the prompt to the user */
		display_prompt();
		/* Read the user input */
		read_command(command);
		/* Split the command and arguments */
		/* args[MAX_COMMAND_LENGTH]; */
		argc = 0;
		token = strtok(command, " ");

		while (token != NULL && argc < MAX_COMMAND_LENGTH - 1)
		{
			args[argc++] = token;
			token = strtok(NULL, " ");
		}
		/* The last element of the array must be NULL to indicate the end. */
		args[argc] = NULL;
		/* Check if the user entered the "exit" command */
		if (strcmp(args[0], "exit") == 0)
		{
			/* If so, exit the shell */
			exit_shell();
		}
		/* Check if the user entered the "env" command */
		else if (strcmp(args[0], "env") == 0)
		{
			/* If so, print the current environment variables */
			print_environment();
		}
		/* Execute the user command */
		execute_command(args[0], args, environ);
	}
}
