/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:05:04 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 03:05:13 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **b_list, t_list **a_list, int x)
{
	t_list	*last_b;
	t_list	*last_a;
	t_list	*a;
	t_list	*b;

	b = *b_list;
	a = *a_list;
	if (a == NULL || b == NULL || a->next == NULL || b->next == NULL)
		return ;
	last_a = p_last(a);
	last_a->next = a;
	last_a->prev->next = NULL;
	last_a->prev = NULL;
	last_a->next->prev = last_a;
	*a_list = last_a;
	last_b = p_last(b);
	last_b->next = b;
	last_b->prev->next = NULL;
	last_b->prev = NULL;
	last_b->next->prev = last_b;
	*b_list = last_b;
	if (x != 1)
		write(1, "rrr\n", 4);
}

void	ra(t_list **a, int x)
{
	t_list	*lst_a;
	t_list	*last;

	lst_a = *a;
	last = p_last(lst_a);
	last->next = lst_a;
	lst_a = lst_a->next;
	lst_a->prev = NULL;
	last->next->next = NULL;
	last->next->prev = last;
	*a = lst_a;
	if (x != 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int x)
{
	t_list	*lst_b;
	t_list	*last;

	if (*b == NULL)
		return ;
	lst_b = *b;
	last = p_last(lst_b);
	last->next = lst_b;
	lst_b = lst_b->next;
	lst_b->prev = NULL;
	last->next->next = NULL;
	last->next->prev = last;
	*b = lst_b;
	if (x != 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **b, t_list **a, int x)
{
	t_list	*lst_b;
	t_list	*last;
	t_list	*lst_a;

	if (*b == NULL || *a == NULL)
		return ;
	lst_a = *a;
	last = p_last(lst_a);
	last->next = lst_a;
	lst_a = lst_a->next;
	lst_a->prev = NULL;
	last->next->next = NULL;
	last->next->prev = last;
	*a = lst_a;
	lst_b = *b;
	last = p_last(lst_b);
	last->next = lst_b;
	lst_b = lst_b->next;
	lst_b->prev = NULL;
	last->next->next = NULL;
	last->next->prev = last;
	*b = lst_b;
	if (x != 1)
		write(1, "rr\n", 3);
}
