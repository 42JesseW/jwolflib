/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 21:32:12 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:39:02 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**clear_arr(char **arr, int elems)
{
	int	idx;

	idx = 0;
	while (idx < (elems - 1))
	{
		if (arr[idx] != NULL)
			free(arr[idx]);
		idx++;
	}
	free(arr);
	return (NULL);
}

static int	is_valid_split(char **arr, int elems)
{
	int	idx;

	idx = 0;
	while (idx < (elems - 1))
	{
		if (arr[idx] == NULL)
			return (0);
		idx++;
	}
	return (1);
}

static int	count_elems(const char *s, char c)
{
	int		count;
	size_t	idx;
	size_t	slen;

	idx = 0;
	count = 0;
	slen = ft_strlen(s);
	while (idx <= slen)
	{
		if ((s[idx] == c || s[idx] == '\0') && idx != 0)
		{
			if (s[idx - 1] != c)
				count++;
		}
		idx++;
	}
	return (count + 1);
}

static char	**split_elems(char **arr, char const *s, char c)
{
	int		idx;
	int		start;
	int		slen;

	idx = 0;
	start = 0;
	slen = ft_strlen(s);
	while (idx <= slen)
	{
		if ((s[idx] == c) || (s[idx] == '\0'))
		{
			if (idx == 0)
				start += 1;
			else if (s[idx - 1] == c)
				start = idx + 1;
			else
			{
				*arr = ft_substr(s, start, (idx - start));
				start = idx + 1;
				arr++;
			}
		}
		idx++;
	}
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		elems;

	if (s == NULL)
		return (NULL);
	else
	{
		elems = count_elems(s, c);
		split = malloc(sizeof(char*) * elems);
		if (split == NULL)
			return (NULL);
		else
		{
			split = split_elems(split, s, c);
			*split = NULL;
			split -= (elems - 1);
		}
	}
	return ((is_valid_split(split, elems)) ? split : clear_arr(split, elems));
}
