/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:01:25 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:35:53 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
	return ;
}
