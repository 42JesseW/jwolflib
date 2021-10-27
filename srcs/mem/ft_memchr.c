/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:56:10 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:35:53 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	b;

	ptr = (unsigned char *)s;
	b = c;
	while (n > 0)
	{
		if (*ptr == b)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
