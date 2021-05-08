/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 19:44:48 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:39:18 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*odst;
	size_t	nleft;
	size_t	dlen;

	odst = dst;
	nleft = size;
	while (nleft && *dst != '\0')
	{
		dst++;
		nleft--;
	}
	dlen = dst - odst;
	nleft = size - dlen;
	if (nleft == 0)
		return (dlen + ft_strlen(src));
	dlen += ft_strlcpy(dst, src, nleft);
	return (dlen);
}
