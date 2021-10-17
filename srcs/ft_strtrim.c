/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 20:58:15 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:50:34 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	find_ltrim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	i;
	int		found;

	idx = 0;
	while (s1[idx] != '\0')
	{
		i = 0;
		found = 0;
		while (!found)
		{
			if (s1[idx] == set[i])
				found = 1;
			if (s1[idx] != set[i])
			{
				if (i + 1 == ft_strlen(set))
					return (idx);
			}
			i++;
		}
		idx++;
	}
	return (idx);
}

static size_t	find_rtrim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	i;
	size_t	s1len;
	int		found;

	s1len = ft_strlen(s1);
	idx = s1len - 1;
	while (s1 != (s1 + idx))
	{
		i = 0;
		found = 0;
		while (!found)
		{
			if (s1[idx] == set[i])
				found = 1;
			if (s1[idx] != set[i])
			{
				if (i + 1 == ft_strlen(set))
					return (idx);
			}
			i++;
		}
		idx--;
	}
	return (ft_ternary_int(idx == 0, s1len - 1, idx));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	else if (*set == '\0' || set == NULL)
		return (ft_strdup(s1));
	else
	{
		start = find_ltrim(s1, set);
		end = find_rtrim(s1, set);
		trimmed = ft_calloc((end - start + 2), sizeof(char));
		if (trimmed == NULL)
			return (NULL);
	}
	return (ft_strncpy(trimmed, s1 + start, (end - start + 1)));
}
