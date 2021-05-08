/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 15:56:03 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 14:51:30 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** Move the index forward based on last flag added
** and current place in format
**
**	@ARG	{t_flag*} flag
**	@ARG	{const char*} format
**
**	@RETURN	{int} move
*/

static int	move_idx(t_flag *flag, const char *format)
{
	int		move;
	int		idx;

	move = 0;
	idx = (flag->type == 'w') ? 0 : 1;
	if (format[idx] == '*')
		return (idx);
	if (format[idx] == '0')
	{
		while (format[move + idx] == '0')
			move++;
	}
	if (flag->type == '.')
	{
		if (!pf_ft_isdigit(format[idx]))
			return (move);
		move += (flag->param != 0) ? count_digits(flag->param) : 0;
	}
	else
		move += count_digits(flag->param) - 1;
	return (move);
}

/*
** Resolve % format strings by creating a linked list of flags
**
**	@ARG	{const char*} format
**	@ARG	{t_core*} core
**
**	@RETURN	{int} success
*/

static int	parse_format(const char *format, t_core *core, va_list args)
{
	t_flag	*flag;
	int		idx;

	idx = 1;
	while (format[idx] != '\0')
	{
		flag = NULL;
		if (pf_ft_strchr(SPECS, format[idx]))
		{
			core->cspec = format[idx];
			core->format_len = idx;
			return (1);
		}
		else if (pf_ft_strchr(FLAGS, format[idx]))
			flag = build_flag(format + idx, core, format[idx], args);
		else if (pf_ft_isdigit(format[idx]) || format[idx] == '*')
			flag = build_flag(format + idx, core, 'w', args);
		if (!flag)
			return (0);
		if (flag->type == '.' || flag->type == 'w')
			idx += move_idx(flag, format + idx);
		idx++;
	}
	return (0);
}

static int	resolve_format(const char *format, t_core *core, va_list args,
															int *idx)
{
	ssize_t		ret;

	ret = 1;
	if (parse_format(format + *idx, core, args))
	{
		if (!core->write_funcs[index_of(SPECS, core->cspec)](core, args))
			return (-1);
		*idx += core->format_len;
	}
	else
	{
		ret = pf_ft_putchar_fd(format[*idx], 1);
		if (ret == -1)
			return (ret);
		core->string_len++;
	}
	lstreset_core(core, RST_FORMAT);
	return (ret);
}

/*
** Main printf loop over format string. When a % is found, try
** to parse it to specified format.
**
**	@ARG	{const char*} format
**	@ARG	{va_list} args
**
**	@RETURN	{int} length
*/

static int	real_printf(const char *format, va_list args)
{
	t_core		*core;
	ssize_t		ret;
	int			idx;

	core = build_core();
	if (!core)
		return (-1);
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			if (resolve_format(format, core, args, &idx) == -1)
				return (-1);
		}
		else
		{
			ret = pf_ft_putchar_fd(format[idx], 1);
			if (ret == -1)
				return (-1);
		}
		core->string_len++;
		idx++;
	}
	return (lstreset_core(core, RST_CORE));
}

/*
** Wrapper for real_printf initializing variadic args
**
**  @ARG    {const char*} format
**  @ARG	{...}
**
**	@RETURN	{int} length
*/

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	va_start(args, format);
	len = real_printf(format, args);
	va_end(args);
	return (len);
}
