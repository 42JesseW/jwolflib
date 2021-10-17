/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/18 14:38:08 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:36:28 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (s == NULL)
		return ;
	else
	{
		index = 0;
		while (s[index] != '\0')
		{
			ft_putchar_fd(s[index], fd);
			index++;
		}
	}
	return ;
}
