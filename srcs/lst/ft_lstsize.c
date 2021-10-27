/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/18 22:13:00 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 14:21:19 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		len;

	cur = lst;
	len = 0;
	while (cur != NULL)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}
