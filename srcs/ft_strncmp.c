/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 13:49:47 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:39:31 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*ps1;
	unsigned char	*ps2;

	idx = 0;
	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (idx < n)
	{
		if (ps1[idx] != ps2[idx] || s1[idx] == '\0' || s2[idx] == '\0')
			return (ps1[idx] - ps2[idx]);
		idx++;
	}
	return (0);
}
