#include "cmd_sh.h"

/**
 * dup_str - create a duplicate of the given string
 * @sh_str: given string to be duplicated
 * Return: on success will return a char pointer
 *
 * by: doris_jenny
 */
char *dup_str(const char *sh_str)
{
	size_t _leng = 0;
	char *clone;
	size_t cnt = 0;

	/*check if the src string != NULL*/
	if (sh_str == NULL)
		return (NULL);

	_leng = my_str_len(sh_str);

	clone = malloc(_leng + 1);
	if (clone == NULL)
	{
		return (NULL);
	}

	clone = my_str_cpy(clone, sh_str);
	(void)cnt;

	return (clone);
}

/**
 * my_str_len - my implementation of the str_len
 * @str: the str to count
 * Return: the len of the str
 *
 * by: doris_jenny - E
*/
size_t my_str_len(const char *str)
{
	int i = 0;
	const char *s = str;

	while (s[i] != '\0')
	{
		i++;
	}
	return ((size_t)i);
}

/**
 * my_str_cpy - fnc to copy string from src to dest
 * @dest: the destination to copy to
 * @src: the source to copy from
 * Return: the dest
 *
 * by: doris_jenny - E
*/
char *my_str_cpy(char *dest, const char *src)
{
	int i = 0;
	char *d = dest;
	const char *s = src;

	while ((d[i] = s[i]) != '\0')
	{
		i++;
	}

	return (dest);
}
