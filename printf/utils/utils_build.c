/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_build.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 10:57:36 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:29:10 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

/*
** retrieve parameter for specific flag. -1 if none, -2 if *
**
**	@ARG	{const char*} format
**	@ARG	{char} type
**
**	@RETURN	{int} param
*/

static int	get_flag_param(const char *format, char type, va_list args)
{
	int	param;
	int	idx;

	if (type != '.' && type != 'w')
		return (-1);
	idx = ft_ternary_int(type == 'w', 0, 1);
	if (format[idx] == '*')
		return (va_arg(args, int));
	param = 0;
	while (pf_ft_isdigit(format[idx]))
	{
		param = (param * 10) + (format[idx] - '0');
		idx++;
	}
	return (param);
}

/*
** build t_flag and find its corresponding parameter, then add it
** to the linked list.
**
**	@ARG	{const char*} format
**	@ARG	{char} type
**
**	@RETURN	{t_flag*} flag
*/

t_flag	*build_flag(const char *format, t_core *core
					, char type, va_list args)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->type = type;
	flag->next = NULL;
	flag->param = get_flag_param(format, type, args);
	lstadd_flag_back(&(core->head), flag);
	if (flag->param < 0)
	{
		if (type == '.')
		{
			core->negprec = flag->param;
			flag->param = 0;
		}
		if (type == 'w')
		{
			flag->param *= -1;
			return (build_flag(format, core, '-', args));
		}
	}
	return (flag);
}

/*
** Build write_func arr
**
**	@RETURN {t_write_func*} arr
*/

static t_write_func	*build_write_func_arr(void)
{
	t_write_func	*arr;

	arr = malloc(pf_ft_strlen(SPECS) * sizeof(t_write_func));
	if (!arr)
		return (NULL);
	arr[0] = &write_format_d;
	arr[1] = &write_format_c;
	arr[2] = &write_format_s;
	arr[3] = &write_format_p;
	arr[4] = &write_format_d;
	arr[5] = &write_format_u;
	arr[6] = &write_format_x;
	arr[7] = &write_format_x;
	arr[8] = &write_format_c;
	return (arr);
}

/*
** Build array of t_spec structs
**
**	@RETURN	{t_spec*} arr
*/

static t_spec_func	*build_spec_func_arr(void)
{
	t_spec_func	*arr;

	arr = malloc(pf_ft_strlen(SPECS) * sizeof(t_spec_func));
	if (!arr)
		return (NULL);
	arr[0] = &wrapper_conversion_d;
	arr[1] = &wrapper_conversion_c;
	arr[2] = &wrapper_conversion_s;
	arr[3] = &wrapper_conversion_p;
	arr[4] = &wrapper_conversion_d;
	arr[5] = &wrapper_conversion_u;
	arr[6] = &wrapper_conversion_x;
	arr[7] = &wrapper_conversion_xu;
	arr[8] = &wrapper_conversion_perc;
	return (arr);
}

/*
** Build printf core
**
**	@RETURN	{t_core*} core
*/

t_core	*build_core(int fd)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	if (!core)
		return (NULL);
	core->fd = fd;
	core->cspec = 0;
	core->negprec = 0;
	core->format_len = 0;
	core->string_len = 0;
	core->head = NULL;
	core->spec_funcs = build_spec_func_arr();
	core->write_funcs = build_write_func_arr();
	if (!core->spec_funcs || !core->write_funcs)
	{
		if (core->spec_funcs)
			free(core->spec_funcs);
		if (core->write_funcs)
			free(core->write_funcs);
		free(core);
		return (NULL);
	}
	return (core);
}
