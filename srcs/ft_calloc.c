/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 15:57:48 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:36:01 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	b;

	b = nmemb * size;
	ptr = malloc(b);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, b);
	return (ptr);
}
