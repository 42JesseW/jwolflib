/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrfree.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 14:37:41 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:37:43 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strarrfree(char ***str)
{
	char	**p;
	int		idx;

	if (!(*str))
		return ;
	idx = 0;
	p = *str;
	while (p[idx] != NULL)
	{
		free((void *)p[idx]);
		idx++;
	}
	free(p);
	*str = NULL;
}
