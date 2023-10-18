#include "cmd_sh.h"

/**
 * writeToStdout - write to the std output
 * @cmd_String: cmd and argvs as input from user
 * Return: on success - returns 0.
 *
 * by: doris_jenny
 */

void writeToStdout(const char *cmd_String)
{
	size_t str_len = 0;

	while (cmd_String[str_len] != '\0')
	{
		str_len++;
	}

	write(STDOUT_FILENO, cmd_String, str_len);
}


/**
 * _prompt - write to the fd of 1 the prompt
 * @_print: the string to be written
 * Return: on sucess- returns the number of chr written.
 *
 * by: doris_jenny
 */

int _prompt(char *_print)
{
	int cnt_chr;

	for (cnt_chr = 0; _print[cnt_chr] != '\0';)
	{
		cnt_chr++;
	}
	write(1, _print, cnt_chr);
	return (cnt_chr);
}
