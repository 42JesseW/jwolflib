/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/24 10:41:00 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:41:12 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 32

# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_lst
{
	int					fd;
	long				idx;
	char				*fbuffer_original;
	char				*fbuffer;
	struct s_gnl_lst	*next;
}	t_gnl_lst;

int						get_next_line(int fd, char **line);

char					*extend_line(t_gnl_lst *lst, long *remainder);

char					*gnl_ft_substr(char const *s, unsigned int start,
							size_t len);

size_t					gnl_ft_strlcpy(char *dst, const char *src, size_t size);

void					*gnl_ft_calloc(size_t nmemb, size_t size);

char					*gnl_ft_strchr(const char *s, int c);

#endif
