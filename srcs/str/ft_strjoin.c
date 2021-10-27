/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 20:51:28 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:39:15 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	s1len;
	size_t	s2len;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	p = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!p)
		return (p);
	ft_strlcpy(p, s1, (s1len + 1));
	ft_strlcat(p, s2, (s1len + s2len + 1));
	return (p);
}
