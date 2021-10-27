#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft.h>

static char	*get_string(const char *s, char **str)
{
	char	*tmp;
	char	*dup;

	dup = ft_strdup(s);
	if (!dup)
	{
		free((*str));
		return (NULL);
	}
	if (!(*str))
		tmp = dup;
	else
	{
		tmp = ft_strjoin(*str, dup);
		free(dup);
	}
	free((*str));
	*str = tmp;
	return (*str);
}

/*
** Combine n strings into one.
**	- Will return NULL if n == 0.
**	- Strings passed via variadic arguments
**	  are duplicated using strdup and further
**	  processed from there.
**	- If a NULL pointer is passed as an argument,
**	  it is ignored.
**
**	@PARAM	{int}	n
**	@RETURN	{char*}	str
*/

char	*ft_strnjoin(int n, ...)
{
	char	*str;
	char	*dup;
	int		idx;
	va_list	strings;

	if (!n || n < 0)
		return (NULL);
	idx = 0;
	str = NULL;
	va_start(strings, n);
	while (idx < n)
	{
		dup = va_arg(strings, char *);
		if (dup)
		{
			str = get_string(dup, &str);
			if (!str)
				return (NULL);
		}
		idx++;
	}
	va_end(strings);
	return (str);
}
