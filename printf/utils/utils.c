/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 15:22:30 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 14:50:16 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				idx;

	if (s1 == NULL || s2 == NULL)
		return ((s1 == NULL) ? -1 : 1);
	idx = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (str1[idx] != '\0')
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
		idx++;
	}
	return (str1[idx] - str2[idx]);
}

char		*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = pf_ft_strlen((const char *)s) - 1;
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

int			count_digits(int n)
{
	int count;

	count = 1;
	if (n < 0)
		n = (n == INT_MIN) ? INT_MAX : -n;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int			count_digits_u_base(uintptr_t n, unsigned long base)
{
	int count;

	count = 1;
	while (n > (base - 1))
	{
		n /= base;
		count++;
	}
	return (count);
}

int			index_of(char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
