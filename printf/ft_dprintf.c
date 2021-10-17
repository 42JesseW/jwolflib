/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 15:32:55 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:33:08 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			len;

	va_start(args, format);
	len = real_printf(fd, format, args);
	va_end(args);
	return (len);
}
