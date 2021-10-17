/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:47:32 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:36:03 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = s1;
	ps2 = (unsigned char *)s2;
	if (s1 == NULL && s2 == NULL && n > 0)
		return (NULL);
	else
	{
		while (n > 0)
		{
			*ps1 = *ps2;
			ps1++;
			ps2++;
			n--;
		}
	}
	return (s1);
}
