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

#include "libft.h"

/*
**	DESCRIPTION:
**	- A simple function that takes the memory address
**	  of an array of strings as its argument. It frees
**	  all char pointers inside of the array until it
**	  finds a NULL pointer. It then frees the original
**	  pointer and sets it to NULL.
*/

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
