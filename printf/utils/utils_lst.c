/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 11:30:18 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/10/17 15:26:11 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int	lstreset_core(t_core *core, int type)
{
	t_flag	*cur;
	t_flag	*prev;
	int		len;

	core->cspec = 0;
	core->format_len = 0;
	core->negprec = 0;
	cur = core->head;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	if (type == RST_FORMAT)
		core->string_len--;
	len = core->string_len;
	core->head = NULL;
	if (type == RST_CORE)
	{
		free(core->spec_funcs);
		free(core->write_funcs);
		free(core);
	}
	return (len);
}

/*
** Retrieve a flag from the linked list if it exists
**
**	@ARG	{t_flag*} head
**	@ARG	{char} type
**
**	@RETURN	{t_flag*} flag
*/

t_flag	*lstget_flag(t_flag *head, char type)
{
	t_flag	*cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->type == type)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

/*
** Override an element. - overides 0 and + overides 'space'
**
**	@ARG	{t_core*} head
**	@ARG	{char} type
**
**	@RETURN {int} success
*/

static int	lstoveride_flag(t_flag *head, t_flag *new)
{
	t_flag	*flag;
	char	type;

	type = new->type;
	if (type == '-' || type == '+')
	{
		flag = lstget_flag(head, ft_ternary_int((type == '-'), '0', ' '));
		if (flag)
		{
			flag->type = type;
			free(new);
			return (1);
		}
	}
	if (type == '0' || type == ' ')
	{
		if (lstget_flag(head, ft_ternary_int((type == '0'), '-', '+')))
		{
			free(new);
			return (1);
		}
	}
	return (0);
}

/*
** Add a flag to the linked list if conditions are met
**
**	@ARG	{t_flag**} head
**	@ARG	{t_flag*} flag
**
**	@RETURN
*/

void	lstadd_flag_back(t_flag **head, t_flag *flag)
{
	t_flag	*cur;

	if (!(*head))
		*head = flag;
	else
	{
		if (lstoveride_flag(*head, flag))
			return ;
		cur = *head;
		while (cur != NULL)
		{
			if (cur->type == flag->type)
			{
				cur->param = flag->param;
				free(flag);
				return ;
			}
			if (!(cur->next))
			{
				cur->next = flag;
				return ;
			}
			cur = cur->next;
		}
	}
}
