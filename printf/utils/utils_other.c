/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_other.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 15:12:49 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:23:03 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int	pf_ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

ssize_t	pf_ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	pf_ft_putstr_fd(char *s, int fd)
{
	ssize_t	len;
	ssize_t	ret;
	int		index;

	len = 0;
	if (s == NULL)
		return (len);
	else
	{
		index = 0;
		while (s[index] != '\0')
		{
			ret = pf_ft_putchar_fd(s[index], fd);
			if (ret == -1)
				return (ret);
			len += ret;
			index++;
		}
	}
	return (len);
}

/*
** Exeucte 2 write functions in a specific order
**
**	@ARG	{t_disp} disp
**	@ARG	{t_core*} core
**	@ARG	{char*} str
**
**	@RETURN	{int} success
*/

int	write_format_disp2(t_dispatch2 disp, t_core *core, char *str)
{
	int	err;

	err = disp.one(core, str);
	err = disp.two(core, str);
	return (err == 2);
}

/*
** Exeucte 3 write functions in a specific order
**
**	@ARG	{t_disp} disp
**	@ARG	{t_core*} core
**	@ARG	{char*} str
**
**	@RETURN	{int} success
*/

int	write_format_disp3(t_dispatch3 disp, t_core *core, char *str)
{
	int	err;

	err = disp.one(core, str);
	err = disp.two(core, str);
	err = disp.three(core, str);
	return (err == 3);
}
