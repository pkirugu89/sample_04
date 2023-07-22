#include "main.h"
/* #include "path.c" */

void execute_command(char *command, char **args, char **env)
{
	char *cmd_path;
	pid_t pid;
	int status, exit_status;
	/* check if the command is a built-in command */
	if (strcmp(command, "printenv") == 0)
	{
		print_environment();
		return;
	}
	/* check if the command is a full path to an executable
	 */
	if (access(command, X_OK) == 0)
	{
		cmd_path = strdup(command);
	}
	else
	{
		cmd_path = path_lookup(command);
		
		/* If the command is not found, print an error message and return */
		if (cmd_path == NULL)
		{
			printf("Command not found: %s\n", command);
			return;
		}
	}
	
	/* Fork a new process to execute the command */
	pid = fork();
	printf("cmd path: %s\n",cmd_path);
	
	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process: execute the command with arguments */
		execve(cmd_path, args, env);
		
		/* If execution reaches here, there was an error with execve */
		perror("Command execution error");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process: wait for the child to finish */
		/* int status; */

		wait(&status);
		
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				/* Non-zero exit status indicates an error */
				
				printf("Command returned with an error (exit status: %d)\n", exit_status);
			}
		}
		else if (WIFSIGNALED(status))
		{
			/* If the process was terminated by a signal */
			printf("Command terminated by signal\n");
		}
		
		/* Free the memory allocated for the command path */
		free(cmd_path);
	}
}
