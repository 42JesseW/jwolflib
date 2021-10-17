/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer_x.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 13:12:02 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:02:34 by jevan-de      ########   odam.nl         */
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

static int	write_width_x(t_core *core, char *str)
{
	t_flag	*width;
	char	chpad;
	int		strlen;
	int		len;

	strlen = (int)pf_ft_strlen(str);
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
		pf_ft_putchar_fd(chpad, core->fd);
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

static int	write_prefix_x(t_core *core, char *str)
{
	char	*prefix;

	prefix = NULL;
	if (lstget_flag(core->head, '#') && ft_strcmp(str, "0") != 0)
		prefix = ft_ternary_charp(core->cspec == 'x', "0x", "0X");
	if (prefix)
	{
		pf_ft_putstr_fd(prefix, core->fd);
		core->string_len += 2;
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

static int	write_spec_x(t_core *core, char *str)
{
	t_flag	*precision;
	int		len;

	precision = lstget_flag(core->head, '.');
	if (precision && precision->param > (int)pf_ft_strlen(str))
	{
		len = precision->param - pf_ft_strlen(str);
		core->string_len += len;
		while (len)
		{
			pf_ft_putchar_fd('0', core->fd);
			len--;
		}
	}
	if (!(is_zero_edge(core, str)))
	{
		pf_ft_putstr_fd(str, core->fd);
		core->string_len += pf_ft_strlen(str);
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

int	write_format_x(t_core *core, va_list args)
{
	int		ret;
	char	*str;

	str = core->spec_funcs[index_of(SPECS, core->cspec)](args);
	if (!str)
		return (-1);
	if (lstget_flag(core->head, '-'))
		ret = write_format_disp3((t_dispatch3){
				&write_prefix_x, &write_spec_x, &write_width_x}, core, str);
	else
	{
		if (lstget_flag(core->head, '0'))
			ret = write_format_disp3((t_dispatch3){
					&write_prefix_x, &write_width_x, &write_spec_x}, core, str);
		else
			ret = write_format_disp3((t_dispatch3){
					&write_width_x, &write_prefix_x, &write_spec_x}, core, str);
	}
	free(str);
	return (ft_ternary_int(ret != 0, core->format_len, -1));
}
