#include "cmd_sh.h"
#include <string.h>

/**
 * split_command - Decompose and display strings
 * @_pathName: command itself(the user's command)
 * @cmd_String: The string to be divided into tokens
 * Return: void.
 *
 * by: doris_jenny
 */

void split_command(const char *cmd_String, char *_pathName)
{
	const char *dlmt = " \n";
	char *clone = dup_str(cmd_String);
	char *nxt_sh_cmd = NULL;
	int _counter = 0;
	int cnt;
	char **tokens;

	if (clone == NULL)
	{
		perror("Memory alloction failed");
		return;
	}

	tokens = malloc(sizeof(char *) * 10);
	if (tokens == NULL)
	{
		perror("Memory allocation failed");
		free(clone);
		return;
	}

	nxt_sh_cmd = usrd_strtok(clone, dlmt);

	while (nxt_sh_cmd != NULL && _counter < 10)
	{
		tokens[_counter] = dup_str(nxt_sh_cmd);
		_counter++;
		nxt_sh_cmd = usrd_strtok(NULL, dlmt);
	}

	if (_counter > 0)
	{
		tokens[_counter] = NULL;
		execute_cmd(tokens[0], tokens, _pathName);
		for (cnt = 0; cnt < _counter; cnt++)
			free(tokens[cnt]);
	}
	free(tokens);
	free(clone);
}
