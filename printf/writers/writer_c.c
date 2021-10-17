/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer_c.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/20 16:01:21 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:21:31 by jevan-de      ########   odam.nl         */
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

static int	write_width_c(t_core *core, char *str)
{
	t_flag	*width;
	char	chpad;
	int		len;

	width = lstget_flag(core->head, 'w');
	if (!width)
		return (0);
	chpad = ft_ternary_int(!!lstget_flag(core->head, '0'), '0', ' ');
	len = width->param;
	len -= ft_ternary_int((int)pf_ft_strlen(str) < len,
			(int)pf_ft_strlen(str), len);
	len -= ft_ternary_int(*str == '\0' && width->param > 0, 1, 0);
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

static int	write_spec_c(t_core *core, char *str)
{
	pf_ft_putchar_fd(*str, core->fd);
	core->string_len++;
	return (1);
}

/*
** Write format for spec c to stdout in correct order and return format length
**
**	@ARG	{t_core*} core
**	@ARG	{va_list} args
**
**	@RETURN	{int} length
*/

int	write_format_c(t_core *core, va_list args)
{
	int		ret;
	char	*str;

	str = core->spec_funcs[index_of(SPECS, core->cspec)](args);
	if (!str)
		return (-1);
	if (lstget_flag(core->head, '-'))
		ret = write_format_disp2((t_dispatch2){
				&write_spec_c, &write_width_c}, core, str);
	else
	{
		if (lstget_flag(core->head, '0'))
			ret = write_format_disp2((t_dispatch2){
					&write_width_c, &write_spec_c}, core, str);
		else
			ret = write_format_disp2((t_dispatch2){
					&write_width_c, &write_spec_c}, core, str);
	}
	free(str);
	return (ft_ternary_int(ret != 0, core->format_len, -1));
}
