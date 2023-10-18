#include "cmd_sh.h"

/**
 * main - Entry point
 * @argc: counts the no argument
 * @argv: argument to be counted
 * Return: 1 on success
 */

int main(int argc, char *argv[])
{
	/*program name*/
	char *_pathName = NULL;
	/*for the getline*/
	char *buff = NULL;
	size_t n = 0;

	(void)argc;
	_pathName = argv[0];

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			_prompt("$ ");
			buff = c_getline(buff, &n);


			ctrl_cmp(buff, "exit\n", argv);
			ctrl_cmp(buff, "env\n", argv);

			split_command(buff, _pathName);
		}
	}
	else
	{
		while (getline(&buff, &n, stdin) != -1)
		{
			if (comp_str(buff, "exit\n") == 0)
			{
				free(buff);
				exit(0);
			}
			else
				split_command(buff, _pathName);
		}
	}
	free(buff);
	return (0);
}

/**
 * ctrl_cmp - checks if the buff has the "exit" or "env"
 * @buff: the str to check
 * @check: the check phrase (cases like: "exit" or "env")
 * @argv: env variables
 * Return: void.
 *
 * by: doris_jenny - E
*/
void ctrl_cmp(char *buff, char *check, char *argv[])
{
	(void)check;
	if (comp_str(buff, "exit\n") == 0)
	{
		free(buff);
		exit(0);
	}
	else if (comp_str(buff, "env\n") == 0)
	{
		_env_p(argv);
	}
}


/**
 * c_getline - executes the getline when in interactive mode
 * @buff: the buffer to be store in what was read by getline
 * @n: the size of the buff before and after
 * Return: always sucess - char * buff
 *
 * by: doris_jenny - E
*/
char *c_getline(char *buff, size_t *n)
{
	if (isatty(STDIN_FILENO))
	{
		if (getline(&buff, n, stdin) == -1)
		{
			free(buff);
			exit(0);
		}
	}
	return (buff);
}
