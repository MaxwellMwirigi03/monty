/*
 * File: tokenize_string.c
 * Auth: Bennett Dixon
 */

#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/*Takes a string and seperates its words.*/
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wrdLen, x, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wrdLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wrdLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		x = 0;
		while (x < wrdLen)
		{
			words[i][x] = *(str + x);
			x++;
		}
		words[i][x] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/*Checks if stream has delimitor char*/
int is_delim(char ch, char *delims)
{
	int n = 0;

	while (delims[n])
	{
		if (delims[n] == ch)
			return (1);
		n++;
	}
	return (0);
}

/*Gets the word length of cur word in str*/
int get_word_length(char *str, char *delims)
{
	int wrdLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wrdLen++;
		}
		if (wrdLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wrdLen);
}

/*Gets the word count of a string*/
int get_word_count(char *str, char *delims)
{
	int c = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			c++;
		}
		i++;
	}
	return (c);
}

/*Gets the next word in a string*/
char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
