/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrappers_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 17:14:01 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:14:57 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

char	*wrapper_conversion_d(va_list args)
{
	return (ft_itoa_base(va_arg(args, signed int), 10));
}

char	*wrapper_conversion_p(va_list args)
{
	return (ft_itoa_u_base((uintptr_t)va_arg(args, void *), 16, 0));
}

char	*wrapper_conversion_u(va_list args)
{
	return (ft_itoa_u_base(va_arg(args, unsigned int), 10, 0));
}

char	*wrapper_conversion_x(va_list args)
{
	return (ft_itoa_u_base(va_arg(args, unsigned int), 16, 0));
}

char	*wrapper_conversion_xu(va_list args)
{
	return (ft_itoa_u_base(va_arg(args, unsigned int), 16, 1));
}
