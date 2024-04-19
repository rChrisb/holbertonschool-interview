#include "regex.h"

/**
 * regex_match - Check if a pattern matches a string
 * @str: The string to check
 * @pattern: The pattern to match against
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	if (*str == '\0' && *pattern == '\0') /* Base case: both strings are empty */
		return (1);

	if (*pattern == '*' && *(pattern + 1) == '\0')
		return (1);

	if (*pattern == '*' && *(pattern + 1) == '\0' && *str == '\0')
		return (1);

	if (*pattern == *str || (*pattern == '.' && *str != '\0'))
	{
		if (*(pattern + 1) == '*')
		{
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		}
		return (regex_match(str + 1, pattern + 1));
	}
	}

	if (*pattern == '*')
	{
		return (regex_match(str, pattern + 1));
	}

	return (0);
}
