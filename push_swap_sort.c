/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:51:55 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:51:57 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_mirror(t_list *a, t_list **b)
{
	t_list	*tp;
	t_list	*tp_b;

	tp = a;
	tp_b = *b;
	while (tp != NULL)
	{
		p_addback(&tp_b, p_new(tp->val));
		tp = tp->next;
	}
	*b = tp_b;
}

void	push_range_to_b(t_list **stack_a, t_list **stack_b, int id)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		range_id;

	i = 0;
	range_id = id;
	a = *stack_a;
	b = *stack_b;
	while (a != NULL)
	{
		if (a->index > range_id)
			ra(&a, 0);
		else
		{
			pb(&a, &b, 0);
			if (b->index < i)
				rb(&b, 0);
			i++;
			range_id++;
		}
	}
	*stack_b = b;
	*stack_a = a;
}

void	push_swap_sorting(t_list **stack_a, t_list **stack_b)
{
	int		range_id;
	t_list	*range_array;

	range_array = NULL;
	list_mirror(*stack_a, &range_array);
	normal_sort(&range_array);
	index_stack_a(*stack_a, range_array);
	if (p_last(range_array)->index > 99)
		range_id = 35;
	else
		range_id = 15;
	if (p_last(range_array)->index <= 16)
		range_id = 5;
	push_range_to_b(stack_a, stack_b, range_id);
	p_free(range_array);
	push_to_a(stack_a, stack_b);
}
