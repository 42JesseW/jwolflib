/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/24 10:40:29 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:41:42 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_gnl_lst	*get_gnl_lst(t_gnl_lst **head, int fd)
{
	t_gnl_lst	*cur;
	t_gnl_lst	*prev;
	t_gnl_lst	*new;

	cur = *head;
	while (cur != NULL)
	{
		if (cur->fd == fd)
			return (cur);
		prev = cur;
		cur = cur->next;
	}
	new = malloc(sizeof(t_gnl_lst));
	if (new == NULL)
		return (NULL);
	new->fbuffer = NULL;
	new->fd = fd;
	new->idx = 0;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
		prev->next = new;
	return (new);
}

int			cleanup_get_next_line(t_gnl_lst **head, t_gnl_lst *lst, char **line)
{
	t_gnl_lst	*cur;
	t_gnl_lst	*prev;

	if (*head == NULL || lst == NULL)
		return (-1);
	else
	{
		cur = *head;
		prev = NULL;
		while (cur->fd != lst->fd)
		{
			if (cur->next == NULL)
				return (-1);
			prev = cur;
			cur = cur->next;
		}
		if (prev != NULL)
			prev->next = cur->next;
		if (cur->fbuffer_original != NULL)
			free(cur->fbuffer_original);
		if (cur == *head)
			*head = (*head)->next;
		free(cur);
	}
	return ((line == NULL || *line == NULL) ? -1 : 0);
}

int			find_line_end(t_gnl_lst **head, t_gnl_lst *lst, char **line)
{
	char	*ptr;

	ptr = gnl_ft_strchr(lst->fbuffer, '\n');
	if (ptr != NULL)
	{
		*line = gnl_ft_substr(lst->fbuffer, 0, (ptr - lst->fbuffer));
		if (*line == NULL)
			return (cleanup_get_next_line(head, lst, line));
		lst->idx = (ptr + 1) - lst->fbuffer;
		lst->fbuffer += lst->idx;
		return (1);
	}
	return (0);
}

int			read_line(char **line, t_gnl_lst *lst, t_gnl_lst **head)
{
	ssize_t		size;
	size_t		slen;
	long		remainder;
	int			ret;

	size = 1;
	remainder = 0;
	while (size > 0)
	{
		lst->fbuffer = extend_line(lst, &remainder);
		if (lst->fbuffer == NULL)
			return (cleanup_get_next_line(head, lst, line));
		size = read(lst->fd, lst->fbuffer + remainder, BUFFER_SIZE);
		if (size == -1)
			return (cleanup_get_next_line(head, lst, NULL));
		ret = find_line_end(head, lst, line);
		if (ret == -1 || ret == 1)
			return (ret);
	}
	slen = 0;
	while (lst->fbuffer[slen] != '\0')
		slen++;
	*line = gnl_ft_substr(lst->fbuffer, 0, slen);
	return (cleanup_get_next_line(head, lst, line));
}

int			get_next_line(int fd, char **line)
{
	static t_gnl_lst	*head;
	t_gnl_lst			*lst;
	int					ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (cleanup_get_next_line(&head, NULL, line));
	lst = get_gnl_lst(&head, fd);
	if (lst == NULL)
		return (cleanup_get_next_line(&head, lst, line));
	if (lst->fbuffer != NULL)
	{
		ret = find_line_end(&head, lst, line);
		if (ret == -1 || ret == 1)
			return (ret);
	}
	return (read_line(line, lst, &head));
}
