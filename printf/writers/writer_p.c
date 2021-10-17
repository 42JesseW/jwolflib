/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 10:18:24 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:07:55 by jevan-de      ########   odam.nl         */
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

static int	write_width_p(t_core *core, char *str)
{
	t_flag	*width;
	char	chpad;
	int		strlen;
	int		len;

	strlen = ft_ternary_int(is_zero_edge(core, str), 0, (int)pf_ft_strlen(str));
	width = lstget_flag(core->head, 'w');
	if (!width)
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

static int	write_prefix_p(t_core *core, char *str)
{
	(void)str;
	pf_ft_putstr_fd("0x", core->fd);
	core->string_len += 2;
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

static int	write_spec_p(t_core *core, char *str)
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
** Write format for spec p to stdout in correct order and return format length
**
**	@ARG	{t_core*} core
**	@ARG	{va_list} args
**
**	@RETURN	{int} length
*/

int	write_format_p(t_core *core, va_list args)
{
	int		ret;
	char	*str;

	str = core->spec_funcs[index_of(SPECS, core->cspec)](args);
	if (!str)
		return (-1);
	if (lstget_flag(core->head, '-'))
		ret = write_format_disp3((t_dispatch3){
				&write_prefix_p, &write_spec_p, &write_width_p}, core, str);
	else
	{
		if (lstget_flag(core->head, '0') && (!lstget_flag(core->head, '.')
				|| (lstget_flag(core->head, '.') && core->negprec != 0)))
			ret = write_format_disp3((t_dispatch3){
					&write_prefix_p, &write_width_p, &write_spec_p}, core, str);
		else
			ret = write_format_disp3((t_dispatch3){
					&write_width_p, &write_prefix_p, &write_spec_p}, core, str);
	}
	free(str);
	return (ft_ternary_int(ret != 0, core->format_len, -1));
}
