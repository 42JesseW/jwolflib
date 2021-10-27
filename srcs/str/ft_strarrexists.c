/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrexists.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 14:37:34 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:37:38 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_strarrexists(char **arr, char *str)
{
	int	idx;

	if (!arr || !(*arr) || !str)
		return (0);
	idx = 0;
	while (arr[idx])
	{
		if (ft_strcmp(arr[idx], str) == 0)
			return (1);
		idx++;
	}
	return (0);
}
