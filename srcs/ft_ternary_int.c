/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ternary_int.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 14:52:44 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:52:49 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ternary_int(int condition, int a, int b)
{
	if (condition)
		return (a);
	return (b);
}
