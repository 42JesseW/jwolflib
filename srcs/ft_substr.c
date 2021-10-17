/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 16:44:04 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:39:50 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	dest = NULL;
	if (s == NULL)
		return (NULL);
	else if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest)
			ft_strlcpy(dest, s + start, (len + 1));
	}
	return (dest);
}
