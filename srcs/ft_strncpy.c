/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/22 14:12:09 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:39:34 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*dst;
	size_t	idx;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	else
	{
		idx = 0;
		dst = dest;
		while (n > 0)
		{
			if (src[idx] != '\0')
			{
				*dst = src[idx];
				idx++;
			}
			else
				*dst = '\0';
			dst++;
			n--;
		}
	}
	return (dest);
}
