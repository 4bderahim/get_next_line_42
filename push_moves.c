/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:54:07 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:54:10 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_len(t_list *list)
{
	int	count;

	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

void	push_to_stack_a(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	if (tmp_b->next == NULL)
	{
		tmp_b->next = tmp_a;
		tmp_b->next->prev = tmp_b;
		tmp_b->prev = NULL;
		tmp_a = tmp_b;
		tmp_b = NULL;
	}
	else
	{
		tmp_b = tmp_b->next;
		tmp_b->prev->next = tmp_a;
		tmp_a->prev = tmp_b->prev;
		tmp_b->prev = NULL;
		tmp_a = tmp_a->prev;
		tmp_a->prev = NULL;
	}
	*a = tmp_a;
	*b = tmp_b;
}

void	pa(t_list **list_a, t_list **list_b, int x)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (*list_b == NULL)
		return ;
	tmp_a = *list_a;
	tmp_b = *list_b;
	if (tmp_a == NULL)
	{
		tmp_a = tmp_b;
		tmp_b = tmp_b->next;
		tmp_b->prev = NULL;
		tmp_a->next = NULL;
		tmp_a->prev = NULL;
	}
	else
		push_to_stack_a(&tmp_a, &tmp_b);
	*list_a = tmp_a;
	*list_b = tmp_b;
	if (x != 1)
		write(1, "pa\n", 3);
}

void	push_to_stack_b(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	if (tmp_a->next == NULL)
	{
		tmp_a->next = tmp_b;
		tmp_a->next->prev = tmp_a;
		tmp_a->prev = NULL;
		tmp_b = tmp_a;
		tmp_a = NULL;
	}
	else
	{
		tmp_a = tmp_a->next;
		tmp_a->prev->next = tmp_b;
		tmp_b->prev = tmp_a->prev;
		tmp_a->prev = NULL;
		tmp_b = tmp_b->prev;
		tmp_b->prev = NULL;
	}
	*a = tmp_a;
	*b = tmp_b;
}

void	pb(t_list **list_a, t_list **list_b, int x)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (*list_a == NULL)
		return ;
	tmp_a = *list_a;
	tmp_b = *list_b;
	if (tmp_b == NULL)
	{
		tmp_b = tmp_a;
		tmp_a = tmp_a->next;
		tmp_a->prev = NULL;
		tmp_b->next = NULL;
		tmp_b->prev = NULL;
	}
	else
		push_to_stack_b(&tmp_a, &tmp_b);
	*list_a = tmp_a;
	*list_b = tmp_b;
	if (x != 1)
		write(1, "pb\n", 3);
}
