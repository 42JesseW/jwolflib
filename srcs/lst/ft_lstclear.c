/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/19 11:16:45 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:37:13 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (del == NULL)
		return ;
	next = *lst;
	while (next)
	{
		cur = next;
		next = cur->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
	return ;
}
