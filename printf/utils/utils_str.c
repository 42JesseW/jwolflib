/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 15:12:54 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 14:50:06 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

void			*pf_ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	void			*ptr;
	size_t			b;

	b = nmemb * size;
	ptr = malloc(b);
	if (!ptr)
		return (ptr);
	p = ptr;
	while (b > 0)
	{
		*p = '\0';
		p++;
		b--;
	}
	return (ptr);
}

size_t			pf_ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static size_t	pf_ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*s;
	size_t		nleft;

	if (src == NULL || dst == NULL)
		return (0);
	s = (char*)src;
	nleft = size;
	if (nleft != 0)
	{
		nleft -= 1;
		while (*s != '\0' && nleft != 0)
		{
			*dst = *s;
			dst++;
			s++;
			nleft--;
		}
	}
	if (size != 0)
		*dst = '\0';
	while (*s)
		s++;
	return (s - src);
}

char			*pf_ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char			*pf_ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = pf_ft_strlen(s) + 1;
	dup = pf_ft_calloc(sizeof(char) * len, 1);
	if (dup == NULL)
		return (dup);
	pf_ft_strlcpy(dup, s, len);
	return (dup);
}
