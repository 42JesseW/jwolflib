/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer_s.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 09:51:46 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/07/14 16:00:32 by jessevander   ########   odam.nl         */
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

static int	write_width_s(t_core *core, char *str)
{
	t_flag	*width;
	char	chpad;
	int		strlen;
	int		len;

	width = lstget_flag(core->head, 'w');
	if (!width)
		return (0);
	strlen = (int)pf_ft_strlen(str);
	chpad = (lstget_flag(core->head, '0')) ? '0' : ' ';
	len = width->param;
	if (lstget_flag(core->head, '.'))
	{
		if (lstget_flag(core->head, '.')->param < strlen)
			strlen = lstget_flag(core->head, '.')->param;
	}
	len -= (strlen < len) ? strlen : len;
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

static int	write_spec_s(t_core *core, char *str)
{
	t_flag	*precision;
	int		len;
	char	*s;

	s = str;
	len = (int)pf_ft_strlen(str);
	precision = lstget_flag(core->head, '.');
	if (precision && precision->param < len)
		len = precision->param;
	while (len && *s)
	{
		pf_ft_putchar_fd(*s, core->fd);
		core->string_len++;
		len--;
		s++;
	}
	return (1);
}

/*
** Write format for spec s to stdout in correct order and return format length
**
**	@ARG	{t_core*} core
**	@ARG	{va_list} args
**
**	@RETURN	{int} length
*/

int			write_format_s(t_core *core, va_list args)
{
	int		ret;
	char	*str;

	str = core->spec_funcs[index_of(SPECS, core->cspec)](args);
	if (!str)
		return (-1);
	if (core->negprec != 0)
		lstget_flag(core->head, '.')->param = pf_ft_strlen(str);
	if (lstget_flag(core->head, '-'))
		ret = write_format_disp2((t_dispatch2){
			&write_spec_s, &write_width_s}, core, str);
	else
	{
		if (lstget_flag(core->head, '0'))
			ret = write_format_disp2((t_dispatch2){
				&write_width_s, &write_spec_s}, core, str);
		else
			ret = write_format_disp2((t_dispatch2){
				&write_width_s, &write_spec_s}, core, str);
	}
	if (ft_strcmp(str, "(null)") == 0)
		free(str);
	return ((ret != 0) ? core->format_len : -1);
}
