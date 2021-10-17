/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ternary_charp.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 14:58:19 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:59:31 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_ternary_charp(int condition, char *a, char *b)
{
	if (condition)
		return (a);
	return (b);
}
