/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 13:16:17 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:35:42 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (s1 == NULL && s2 == NULL && n > 0)
		return (NULL);
	else if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	else
	{
		d = s1;
		s = s2;
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (d);
}
