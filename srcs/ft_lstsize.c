/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/18 22:13:00 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:37:47 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstsize(t_list *lst)
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
