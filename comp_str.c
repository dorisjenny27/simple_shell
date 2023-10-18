#include "cmd_sh.h"

/**
 * comp_str - This function compares two strings
 * @str_1: first string to compare
 * @str_2: second string to compare
 * Return: 1 on success
 *
 * By: doris_jenny
 */

int comp_str(const char *str_1, const char *str_2)
{
	size_t cnt = 0;

	for (cnt = 0; str_1[cnt] != '\0' && str_2[cnt] != '\0'; )
	{
		if (str_1[cnt] != str_2[cnt])
		{
			return ((int)(str_1[cnt] - str_2[cnt]));
		}
		cnt++;
	}
	if (str_1[cnt] == '\0' && str_2[cnt] == '\0')
	{
		return (0);
	}
	return ((int)(str_1[cnt] - str_2[cnt]));
}
