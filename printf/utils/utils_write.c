/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_write.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/30 12:34:20 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:20:50 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int	get_prefix_len(t_core *core, char *str)
{
	if (core->cspec == 'x' || core->cspec == 'X')
		return (ft_ternary_int((lstget_flag(core->head, '#')
					&& ft_strcmp(str, "0") != 0), 2, 0));
	else if (core->cspec == 'p' || core->cspec == 'u')
		return (0);
	else
		return ((lstget_flag(core->head, '+')
				|| lstget_flag(core->head, ' '))
			|| ft_ternary_int(*str == '-', 1, 0));
}

bool	is_zero_edge(t_core *core, char *str)
{
	return ((core->negprec == 0)
		&& (ft_strcmp(str, "0") == 0)
		&& (lstget_flag(core->head, '.'))
		&& (lstget_flag(core->head, '.')->param == 0));
}

char	get_chpad(t_core *core)
{
	t_flag	*precision;

	if (lstget_flag(core->head, '0'))
	{
		precision = lstget_flag(core->head, '.');
		if (!precision || (precision && core->negprec != 0))
			return ('0');
	}
	return (' ');
}

int	get_width_len(t_core *core, char *str, int strlen, int len)
{
	t_flag	*precision;
	int		preclen;

	precision = lstget_flag(core->head, '.');
	if (precision)
	{
		if (precision->param > len)
			return (-1);
		preclen = ft_ternary_int(precision->param > strlen,
				precision->param - strlen, 0);
		if ((preclen + len + get_prefix_len(core, str))
			<= ft_ternary_int(ft_strcmp(str, "0") == 0, 0, strlen))
			return (-1);
		len -= preclen;
	}
	if (core->cspec == 'p')
		len -= ft_ternary_int((strlen + 2) < len, strlen + 2, len);
	else
	{
		len -= (strlen + get_prefix_len(core, str));
		len += ft_ternary_int(is_zero_edge(core, str), 1, 0);
	}
	return (len);
}

bool	has_width(t_core *core, char *str, int strlen)
{
	t_flag	*width;

	width = lstget_flag(core->head, 'w');
	if (!width)
		return (false);
	if (width->param == 0 && ft_strcmp(str, "0") == 0)
		return (false);
	if ((strlen + get_prefix_len(core, str)) >= width->param)
	{
		if (ft_strcmp(str, "0") != 0)
			return (false);
	}
	return (true);
}
