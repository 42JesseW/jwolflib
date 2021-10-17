/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 21:02:10 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:35:58 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (s1 == NULL && s2 == NULL && n > 0)
		return (NULL);
	else
	{
		ps1 = s1;
		ps2 = (unsigned char *)s2;
		while (n > 0)
		{
			*ps1 = *ps2;
			ps1++;
			if (*ps2 == (unsigned char)c)
				return (ps1);
			ps2++;
			n--;
		}
	}
	return (NULL);
}
