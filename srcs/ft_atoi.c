/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 13:57:17 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:35:35 by jevan-de      ########   odam.nl         */
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

int				ft_atoi(const char *str)
{
	int	value;
	int	sign;
	int	index;

	value = 0;
	sign = 1;
	index = 0;
	str = str + find_ltrim(str, "\a\t\b \v\n\r\f");
	if ((str[index] == '+') || (str[index] == '-'))
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		value = value * 10 + (str[index] - '0');
		index++;
	}
	return (value * sign);
}
