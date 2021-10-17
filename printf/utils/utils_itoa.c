/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_itoa.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 15:32:54 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:28:09 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static char	*calc_string(char *str, int n, int sign, int base)
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
			str[idx] = n % base + ft_ternary_int((n % base > 9), '0' + 39, '0');
			n /= base;
			idx++;
		}
		if (sign)
			str[idx] = '-';
	}
	return (str);
}

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (n < 0 || n == -0)
	{
		if (n == INT_MIN)
			return (pf_ft_strdup("-2147483648"));
		n = -n;
	}
	str = pf_ft_calloc(sizeof(char) * (count_digits(n) + sign + 1), 1);
	if (!str)
		return (str);
	str = calc_string(str, n, sign, base);
	return (ft_strrev(str));
}

char	*ft_itoa_u_base(uintptr_t n, unsigned long base, int capitalized)
{
	char	*str;
	int		diff;
	int		idx;

	str = pf_ft_calloc(sizeof(char) * (count_digits_u_base(n, base) + 1), 1);
	if (!str)
		return (str);
	idx = 0;
	diff = ft_ternary_int(capitalized, 7, 39);
	if (n == 0)
	{
		str[idx] = '0';
		return (str);
	}
	else
	{
		while (n > 0)
		{
			str[idx] = n % base + ft_ternary_int(
					(n % base > 9), '0' + diff, '0');
			n /= base;
			idx++;
		}
	}
	return (ft_strrev(str));
}
