/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 16:17:02 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:39:12 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s) + 1;
	dup = ft_calloc(sizeof(char) * len, 1);
	if (dup == NULL)
		return (dup);
	ft_strlcpy(dup, s, len);
	return (dup);
}
