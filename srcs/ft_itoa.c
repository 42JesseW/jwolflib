/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 23:48:58 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:34:53 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen((const char *)s) - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

static int	count_digits(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		if (n == INT_MIN)
			n = INT_MAX;
		else
			n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*calc_string(char *str, int n, int sign)
{
	int		idx;

	idx = 0;
	if (n == 0)
	{
		str[idx] = '0';
		return (str);
	}
	else
	{
		while (n > 0)
		{
			str[idx] = n % 10 + '0';
			n /= 10;
			idx++;
		}
		if (sign)
			str[idx] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (n < 0 || n == -0)
	{
		if (n == INT_MIN)
			return (ft_strdup("-2147483648"));
		n = -n;
	}
	str = ft_calloc(sizeof(char) * (count_digits(n) + sign + 1), 1);
	if (!str)
		return (str);
	str = calc_string(str, n, sign);
	return (ft_strrev(str));
}
