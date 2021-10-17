/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 13:57:17 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:47:14 by jevan-de      ########   odam.nl         */
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

static double	loop_left(const char *str, int *idx)
{
	double	num;

	num = 0;
	while (ft_isdigit(str[*idx]))
	{
		num = (num * 10.) + (str[*idx] - '0');
		(*idx)++;
	}
	return (num);
}

double	ft_atof(const char *str)
{
	double	num;
	double	decplace;
	int		sign;
	int		idx;

	sign = 1;
	idx = 0 + find_ltrim(str, "\a\t\b \v\n\r\f");
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	num = loop_left(str, &idx);
	if (str[idx] == '.')
		idx++;
	decplace = 1.;
	while (ft_isdigit(str[idx]))
	{
		num = (num * 10) + (str[idx] - '0');
		decplace *= 10.;
		idx++;
	}
	return (sign * (num / decplace));
}
