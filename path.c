#include "main.h"

char *path_lookup(const char *command) 
{
	char *path_env = getenv("PATH");
	char *path = strdup(path_env);
	char *path_entry = strtok(path, ":");
	char cmd_path[MAX_COMMAND_LENGTH];

	if (path_env == NULL)
	{
		return NULL;
	}
	
	/* Duplicate the PATH environment variable to manipulate it */
	/* char *path = strdup(path_env);*/

	if (path == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	
	/* Split the PATH variable into individual directories
	char *path_entry = strtok(path, ":"); */

	while (path_entry != NULL)
	{
		/* char cmd_path[MAX_COMMAND_LENGTH];
		 Combine the directory with the command */
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", path_entry, command);
		
		/* Check if the command exists in the current directory */
		if (access(cmd_path, X_OK) == 0)
		{
			/* Free the memory allocated for the duplicated PATH variable */
			free(path);
			/* Return the path to the command */
			return strdup(cmd_path); 
		}
		
		/* Move to the next directory in the PATH */
		path_entry = strtok(NULL, ":"); 
	} 
	
	/* Free the memory allocated for the duplicated PATH variable */
	free(path);
	/* If the command is not found in any directory, return NULL */
	return NULL; 
}

