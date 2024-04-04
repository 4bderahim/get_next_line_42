/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_list_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:52:22 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:52:25 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*p_new(int val)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list	*p_last(t_list *node)
{
	if (node == NULL)
		return (NULL);
	if (node->next == NULL)
		return (node);
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

void	p_addback(t_list **head, t_list *new)
{
	t_list	*tmp;

	if (!head)
		return ;
	tmp = p_last(*head);
	if (!tmp)
	{
		*head = new;
		return ;
	}
	tmp->next = new;
	new->prev = tmp;
}

void	p_free(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
}

int	add_back_andcheck_max(t_list **main_a, long res, int sign, char *s)
{
	p_addback(main_a, p_new(res * sign));
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
	{
		free(s);
		return (-1);
	}
	return (1);
}
