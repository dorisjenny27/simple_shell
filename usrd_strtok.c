#include "cmd_sh.h"

/**
 * usrd_strtok - usr def fnc to tokenize the str
 * @sh_str: str to be tokenized
 * @dlmt: delimiter
 * Return: on sucess, returns a char
 *
 * by: doris_jenny
 */

char *usrd_strtok(char *sh_str, const char *dlmt)
{
	static char *nxt_sh_tokens;
	char *sh_tokens = NULL;

	if (sh_str != NULL)
		nxt_sh_tokens = sh_str;

	if (nxt_sh_tokens == NULL || *nxt_sh_tokens == '\0')
		return (NULL);

	nxt_sh_tokens += my_strspn(nxt_sh_tokens, dlmt);

	if (*nxt_sh_tokens == '\0')
		return (NULL);

	sh_tokens = nxt_sh_tokens;

	nxt_sh_tokens = sh_tokens + strcspn(sh_tokens, dlmt);

	if (*nxt_sh_tokens != '\0')
	{
		*nxt_sh_tokens = '\0';
		nxt_sh_tokens++;
	}
	return (sh_tokens);
}

/**
 * my_strspn - length of the initial segment of a string 'str'
 * @str: The input string to be analyzed.
 * @accept: A string containing the characters to be counted in 'str'.
 * Return: length of the initial segment of 'str'
 * that contain only char from 'accept'
 *
 * by: doris_jenny - E
*/
size_t my_strspn(const char *str, const char *accept)
{
	size_t count = 0;
	const char *s = str;

	/*While the current character is in the accept string.*/
	while (s[count] && my_strchr(accept, s[count]) != NULL)
	{
		count++;
	}

	return (count);
}


/**
 * my_strchr - Searches for first occurrence of a char 'ch' in 'str'.
 * @str: The input string to be searched.
 * @ch: The character to be found in 'str'.
 * Return: pointer to the first occurrence of 'ch' in 'str'
 * or NULL if 'ch' is not found in the string.
 *
 * by: doris_jenny - E
*/
char *my_strchr(const char *str, int ch)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == ch)
		{
			return ((char *)str); /*Casting const away for compatibility.*/
		}
		count++;
	}
	return (NULL);
}


/**
 * my_strcspn - Calculates the len of initial segment contained in 'reject'
 * @str: The input string to be analyzed.
 * @reject: string containing the characters to be avoided in 'str'.
 * Return: The len of initial segment of 'str' not in any char in 'reject'
 *
 * by: doris_jenny - E
*/
size_t my_strcspn(const char *str, const char *reject)
{
	size_t count = 0;
	const char *s = str;

	while (s[count] != '\0')
	{
		if (my_strchr(reject, s[count]) != NULL)
		{
			return (count);
		}
		count++;
	}

	return (count);
}
