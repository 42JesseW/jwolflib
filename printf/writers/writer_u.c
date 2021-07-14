/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 12:44:28 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/07/14 16:01:03 by jessevander   ########   odam.nl         */
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

static int	write_width_u(t_core *core, char *str)
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
** Write the specification and precision to the screen
**
**	@ARG	{t_core*} core
**	@ARG	{char*} str
**
**	@RETURN	{int} success
*/

static int	write_spec_u(t_core *core, char *str)
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

int			write_format_u(t_core *core, va_list args)
{
	int		ret;
	char	*str;

	str = core->spec_funcs[index_of(SPECS, core->cspec)](args);
	if (!str)
		return (-1);
	if (lstget_flag(core->head, '-'))
		ret = write_format_disp2((t_dispatch2){
			&write_spec_u, &write_width_u}, core, str);
	else
	{
		if (lstget_flag(core->head, '0'))
			ret = write_format_disp2((t_dispatch2){
				&write_width_u, &write_spec_u}, core, str);
		else
			ret = write_format_disp2((t_dispatch2){
				&write_width_u, &write_spec_u}, core, str);
	}
	free(str);
	return ((ret != 0) ? core->format_len : -1);
}
