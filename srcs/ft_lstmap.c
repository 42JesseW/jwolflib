/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/19 15:46:35 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:37:36 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*elem;
	t_list	*cur;

	if (f == NULL)
		return (NULL);
	else
	{
		cur = lst;
		head = NULL;
		while (cur != NULL)
		{
			elem = ft_lstnew(f(cur->content));
			if (elem == NULL)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, elem);
			cur = cur->next;
		}
	}
	return (head);
}
