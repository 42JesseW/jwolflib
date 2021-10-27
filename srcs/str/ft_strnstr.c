/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 11:27:55 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:38:32 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	idx;
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	idx = 0;
	while (s1[idx] != '\0' && idx < n)
	{
		if (s1[idx] == *s2)
		{
			i = 0;
			while (s1[idx + i] == s2[i])
			{
				if (s2[i + 1] == '\0')
					return ((char *)(s1 + idx));
				if (s1[idx + i] == '\0' || (idx + i + 1) == n)
					return (NULL);
				i++;
			}
		}
		idx++;
	}
	return (NULL);
}
