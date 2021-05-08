/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrappers_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 17:14:14 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 14:50:21 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

char		*wrapper_conversion_c(va_list args)
{
	char	*str;

	str = pf_ft_calloc(1, 1);
	if (!str)
		return (NULL);
	*str = (unsigned char)va_arg(args, int);
	return (str);
}

char		*wrapper_conversion_s(va_list args)
{
	char	*str;

	str = va_arg(args, char*);
	if (!str)
		str = pf_ft_strdup("(null)");
	return (str);
}

char		*wrapper_conversion_perc(va_list args)
{
	char	*str;

	(void)args;
	str = pf_ft_calloc(1, 1);
	if (!str)
		return (NULL);
	*str = '%';
	return (str);
}
