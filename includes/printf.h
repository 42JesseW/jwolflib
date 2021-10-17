/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/17 14:47:10 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:32:15 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define SPECS "dcspiuxX%"

# define FLAGS "0-.# +"

# define RST_FORMAT 1

# define RST_CORE 2

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

# include "libft.h"

typedef struct		s_flag
{
	char			type;
	int				param;
	struct s_flag	*next;
}					t_flag;

typedef char		*(*t_spec_func)(va_list);

typedef struct		s_core
{
	int				fd;
	char			cspec;
	int				negprec;
	int				format_len;
	int				string_len;
	t_flag			*head;
	t_spec_func		*spec_funcs;
	int				(**write_funcs)(struct s_core*, va_list);
}					t_core;

typedef int			(*t_write_func)(t_core*, va_list);

typedef struct		s_dispatch3
{
	int	(*one)(t_core*, char*);
	int	(*two)(t_core*, char*);
	int	(*three)(t_core*, char*);
}					t_dispatch3;

typedef struct		s_dispatch2
{
	int	(*one)(t_core*, char*);
	int	(*two)(t_core*, char*);
}					t_dispatch2;

int			ft_printf(const char *format, ...);

int			ft_dprintf(int fd, const char *format, ...);

int			real_printf(int fd, const char *format, va_list args);

/*
** UTILS
*/
t_flag		*build_flag(const char *format, t_core *core
							, char type, va_list args);

t_core		*build_core(int fd);

void		lstadd_flag_back(t_flag **head, t_flag *flag);

int			lstreset_core(t_core *core, int type);

t_flag		*lstget_flag(t_flag *head, char type);

char		*ft_itoa_base(int n, int base);

char		*ft_itoa_u_base(uintptr_t n, unsigned long base, int capitalized);

int			ft_strcmp(const char *s1, const char *s2);

char		*ft_strrev(char *s);

int			count_digits(int n);

int			count_digits_u_base(uintptr_t n, unsigned long base);

int			index_of(char *str, char c);

int			pf_ft_isdigit(int c);

char		get_chpad(t_core *core);

int			get_prefix_len(t_core *core, char *str);

bool		has_width(t_core *core, char *str, int strlen);

bool		is_zero_edge(t_core *core, char *str);

int			get_width_len(t_core *core, char *str, int strlen, int len);

void		*pf_ft_calloc(size_t nmemb, size_t size);

size_t		pf_ft_strlen(const char *s);

char		*pf_ft_strchr(const char *s, int c);

char		*pf_ft_strdup(const char *s);

ssize_t		pf_ft_putstr_fd(char *s, int fd);

ssize_t		pf_ft_putchar_fd(char c, int fd);

int			write_format_disp2(t_dispatch2 disp, t_core *core, char *str);

int			write_format_disp3(t_dispatch3 disp, t_core *core, char *str);

/*
** WRAPPERS
*/
char		*wrapper_conversion_d(va_list args);

char		*wrapper_conversion_c(va_list args);

char		*wrapper_conversion_s(va_list args);

char		*wrapper_conversion_p(va_list args);

char		*wrapper_conversion_u(va_list args);

char		*wrapper_conversion_x(va_list args);

char		*wrapper_conversion_xu(va_list args);

char		*wrapper_conversion_o(va_list args);

char		*wrapper_conversion_perc(va_list args);

/*
** WRITERS
*/
int			write_format_d(t_core *core, va_list args);

int			write_format_c(t_core *core, va_list args);

int			write_format_s(t_core *core, va_list args);

int			write_format_p(t_core *core, va_list args);

int			write_format_u(t_core *core, va_list args);

int			write_format_x(t_core *core, va_list args);

int			write_format_xu(t_core *core, va_list args);

int			write_format_o(t_core *core, va_list args);

int			write_format_perc(t_core *core, va_list args);

#endif