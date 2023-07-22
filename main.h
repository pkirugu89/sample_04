#ifndef SHELL_H
#define SHELL_H

/* Import libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
/* Prototypes */
void display_prompt();
void execute_command(char *command, char **args, char **env);
void read_command(char *command);
void run_shell();
void exit_shell();
void print_environment();
char *path_lookup(const char *command);

#endif
