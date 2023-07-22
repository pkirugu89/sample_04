#include "main.h"

/* The environment is stored in the external variable `environ`. */
extern char **environ;

void print_environment() 
{
	char **env_var = environ;
	while (*env_var != NULL)
	{
		/* Print each environment variable */
		printf("%s\n", *env_var);
		env_var++;
	}
}
