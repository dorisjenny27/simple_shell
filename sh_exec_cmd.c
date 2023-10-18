#include "cmd_sh.h"

/**
 * execute_cmd - fnc to Handles the execution of a command
 * @my_Cmd: cmd to be executed
 * @_pathName: The program's name
 * @arg_vec: The command's arguments
 * Return: void
 *
 * by: doris_jenny
 */
void execute_cmd(const char *my_Cmd, char **const arg_vec, char *_pathName)
{
	if (access(my_Cmd, X_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			execve(my_Cmd, arg_vec, NULL);
			perror(_pathName);
			exit(1);
		}
		else if (pid > 0)
		{
			int status;

			waitpid(pid, &status, 0);
		}
		else
		{
			perror("Fork failed");
		}
	}
	else
	{
		proc_excve(my_Cmd, arg_vec, _pathName);
	}
}

/**
 * proc_excve - Executes my_Cmd using execvp
 * @my_Cmd: Command to be executed
 * @arg_vec: Command arguments
 * @_pathName: Program name
 * Return: void.
 *
 * by: doris_jenny
 */
void proc_excve(const char *my_Cmd, char **const arg_vec, char *_pathName)
{
		pid_t pid = fork();

		if (pid == 0)
		{
			execvp(my_Cmd, arg_vec);
			perror(_pathName);
			exit(1);
		}
		else if (pid > 0)
		{
			int status;

			waitpid(pid, &status, 0);
		}
		else
		{
			perror("Fork failed");
		}
}
