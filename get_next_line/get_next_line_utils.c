/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/24 10:40:36 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:48:17 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*extend_line(t_gnl_lst *lst, long *remainder)
{
	char	*buff;
	long	prev;
	size_t	slen;

	prev = *remainder;
	if (lst->fbuffer != NULL)
	{
		slen = 0;
		while (lst->fbuffer[slen] != '\0')
			slen++;
		*remainder = slen;
	}
	buff = gnl_ft_calloc(*remainder + BUFFER_SIZE + 1, 1);
	if (buff == NULL)
		return (NULL);
	if (lst->fbuffer != NULL)
	{
		if (prev != *remainder)
			gnl_ft_strlcpy(buff, lst->fbuffer, *remainder + 1);
		free(lst->fbuffer_original);
	}
	lst->fbuffer_original = buff;
	return (buff);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

void	*gnl_ft_calloc(size_t nmemb, size_t size)
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

size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*s;
	size_t		nleft;

	if (src == NULL || dst == NULL)
		return (0);
	s = (char *)src;
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

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	slen;

	slen = 0;
	dest = NULL;
	if (s == NULL)
		return (NULL);
	while (s[slen] != '\0')
		slen++;
	if (start >= slen)
		return (gnl_ft_calloc(1, 1));
	else
	{
		if (slen < len)
			len = slen;
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest)
			gnl_ft_strlcpy(dest, s + start, (len + 1));
	}
	return (dest);
}
