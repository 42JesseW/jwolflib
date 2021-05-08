/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer_d.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 12:31:20 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 14:50:36 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

/*
** Write the width to stdout with the correct char
**
**	@ARG	{t_core*} core
**	@ARG	{char*} str
**
**	@RETURN {int} success
*/

static int	write_width_d(t_core *core, char *str)
{
	t_flag	*width;
	char	chpad;
	int		strlen;
	int		len;

	strlen = (*str == '-') ? (int)pf_ft_strlen(str) - 1 : (int)pf_ft_strlen(str);
	width = lstget_flag(core->head, 'w');
	if (!has_width(core, str, strlen))
		return (1);
	chpad = get_chpad(core);
	len = get_width_len(core, str, strlen, width->param);
	if (len == -1)
		return (1);
	core->string_len += len;
	while (len)
	{
		pf_ft_putchar_fd(chpad, 1);
		len--;
	}
	return (1);
}

/*
** Write the format prefix to stdout in correct order
**
**	@ARG	{t_core*} core
**	@ARG	{char*} str
**
**	@RETURN {int} success
*/

static int	write_prefix_d(t_core *core, char *str)
{
	char	prefix;

	prefix = 0;
	if (*str == '-')
		prefix = '-';
	else if (lstget_flag(core->head, '+'))
		prefix = '+';
	else if (lstget_flag(core->head, ' '))
		prefix = ' ';
	if (prefix)
	{
		pf_ft_putchar_fd(prefix, 1);
		core->string_len++;
	}
	return (1);
}

/*
** Write the specification and precision to the screen
**
**	@ARG	{t_core*} core
**	@ARG	{char*} str
**
**	@RETURN	{int} success
*/

static int	write_spec_d(t_core *core, char *str)
{
	t_flag	*precision;
	int		strlen;
	int		len;

	precision = lstget_flag(core->head, '.');
	strlen = (*str == '-') ? (int)pf_ft_strlen(str) - 1 : (int)pf_ft_strlen(str);
	if (precision && precision->param > strlen)
	{
		len = precision->param - ((*str == '-')
			? pf_ft_strlen(str) - 1 : pf_ft_strlen(str));
		core->string_len += len;
		while (len)
		{
			pf_ft_putchar_fd('0', 1);
			len--;
		}
	}
	if (!(is_zero_edge(core, str)))
	{
		pf_ft_putstr_fd(((*str == '-') ? str + 1 : str), 1);
		core->string_len += strlen;
	}
	return (1);
}

/*
** Write format for spec d to stdout in correct order and return format length
**
**	@ARG	{t_core*} core
**	@ARG	{va_list} args
**
**	@RETURN	{int} length
*/

int			write_format_d(t_core *core, va_list args)
{
	int		ret;
	char	*str;

	str = core->spec_funcs[index_of(SPECS, core->cspec)](args);
	if (!str)
		return (-1);
	if (lstget_flag(core->head, '-'))
		ret = write_format_disp3((t_dispatch3){
			&write_prefix_d, &write_spec_d, &write_width_d}, core, str);
	else
	{
		if (lstget_flag(core->head, '0') && !lstget_flag(core->head, '.'))
			ret = write_format_disp3((t_dispatch3){
				&write_prefix_d, &write_width_d, &write_spec_d}, core, str);
		else
			ret = write_format_disp3((t_dispatch3){
				&write_width_d, &write_prefix_d, &write_spec_d}, core, str);
	}
	free(str);
	return ((ret != 0) ? core->format_len : -1);
}
