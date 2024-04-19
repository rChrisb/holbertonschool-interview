#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: the string to scan
 * @pattern: the regular expression
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(const char *str, const char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*pattern == '*' && *(pattern + 1) == '\0')
		return (1);

	if (*pattern == '*' && *(pattern + 1) == '\0' && *str == '\0')
		return (1);

	if (*pattern == *str || (*pattern == '.' && *str != '\0'))
	{
		if (*(pattern + 1) == '*')
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		else
			return (regex_match(str + 1, pattern + 1));
	}

	if (*pattern == '*')
		return (regex_match(str, pattern + 1));

	return (0);
}
