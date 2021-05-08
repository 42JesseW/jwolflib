/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 16:38:33 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:39:20 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*s;
	size_t		nleft;

	if (src == NULL || dst == NULL)
		return (0);
	s = (char*)src;
	nleft = size;
	if (nleft != 0)
	{
		nleft -= 1;
		while (*s != '\0' && nleft != 0)
		{
			*dst = *s;
			dst++;
			s++;
			nleft--;
		}
	}
	if (size != 0)
		*dst = '\0';
	while (*s)
		s++;
	return (s - src);
}
