/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:04:26 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 03:04:54 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list_a, int x)
{
	int	tmp;

	if (!list_a || !list_a->next)
		return ;
	tmp = list_a->next->val;
	list_a->next->val = list_a->val;
	list_a->next->index_b = list_a->index_b;
	list_a->val = tmp;
	tmp = list_a->next->index;
	list_a->next->index = list_a->index;
	list_a->index = tmp;
	if (x != 1)
		write(1, "sa\n", 3);
}

void	sb(t_list *list_b, int x)
{
	int	tmp;

	if (!list_b || !list_b->next)
		return ;
	tmp = list_b->next->val;
	list_b->next->val = list_b->val;
	list_b->val = tmp;
	tmp = list_b->next->index;
	list_b->next->index = list_b->index;
	list_b->index = tmp;
	if (x != 1)
		write(1, "sb\n", 3);
}

void	ss(t_list *list_a, t_list *list_b, int x)
{
	int	tmp;
	int	tmp2;

	if ((!list_a || !list_a->next) || (!list_b || !list_b->next))
		return ;
	tmp = list_a->next->val;
	list_a->next->val = list_a->val;
	list_a->next->index_b = list_a->index_b;
	list_a->val = tmp;
	tmp = list_a->next->index;
	list_a->next->index = list_a->index;
	list_a->index = tmp;
	tmp2 = list_b->next->val;
	list_b->next->val = list_b->val;
	list_b->val = tmp2;
	tmp2 = list_b->next->index;
	list_b->next->index = list_b->index;
	list_b->index = tmp2;
	if (x != 1)
		write(1, "ss\n", 3);
}

void	rra(t_list **a_list, int x)
{
	t_list	*last;
	t_list	*a;

	a = *a_list;
	if (a == NULL || a->next == NULL)
		return ;
	last = p_last(a);
	last->next = a;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next->prev = last;
	*a_list = last;
	if (x != 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b_list, int x)
{
	t_list	*last;
	t_list	*b;

	b = *b_list;
	if (b == NULL || b->next == NULL)
		return ;
	last = p_last(b);
	last->next = b;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next->prev = last;
	*b_list = last;
	if (x != 1)
		write(1, "rrb\n", 4);
}
