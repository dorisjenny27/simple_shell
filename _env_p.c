#include "cmd_sh.h"

/**
 * _env_p - Display the contents of an environment variable array
 * @envp: An array containing environment variable information
 * Return: void
 * By: doris_jenny
 */
void _env_p(char **const envp)
{
	int num = 0;

	for (num = 0; envp[num] != NULL; )
	{
		writeToStdout(envp[num]);
		writeToStdout("\n");
		num++;
	}
}
