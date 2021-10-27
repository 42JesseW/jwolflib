/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 10:56:22 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:38:39 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found;

	if (c == '\0')
		return (ft_strchr(s, c));
	found = NULL;
	while (ft_strchr(s, c) != NULL)
	{
		found = ft_strchr(s, c);
		s = found + 1;
	}
	return ((char *)found);
}
