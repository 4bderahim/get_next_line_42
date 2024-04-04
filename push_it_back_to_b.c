/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_it_back_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:53:08 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:53:10 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_it_to_top_and_pb(t_list **lst_a, t_list **lst_b, int index,
		int rrb_or_rb)
{
	t_list	*a;
	t_list	*b;

	a = *lst_a;
	b = *lst_b;
	while (index != b->index_b)
	{
		if (rrb_or_rb == 1)
			rb(&b, 0);
		else
			rrb(&b, 0);
	}
	pa(&a, &b, 0);
	*lst_a = a;
	*lst_b = b;
}

int	get_max(t_list *bb)
{
	int		i;
	int		j;
	t_list	*b;

	b = bb;
	j = 1;
	i = 0;
	while (b != NULL)
	{
		if (b->index > i)
			i = b->index;
		b = b->next;
	}
	b = bb;
	while (b != NULL)
	{
		if (i == b->index)
			break ;
		b = b->next;
	}
	return (b->index_b);
}

int	indexing_b(t_list *list)
{
	int		index;
	t_list	*t;

	t = list;
	index = 0;
	while (t != NULL)
	{
		t->index_b = index;
		t = t->next;
		index++;
	}
	return (index + 1);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*a;
	int		middle_of_stack_b;
	int		max_index;

	a = *stack_a;
	b = *stack_b;
	while (b != NULL)
	{
		middle_of_stack_b = p_len(b) / 2;
		indexing_b(b);
		max_index = get_max(b);
		if (max_index <= middle_of_stack_b)
		{
			if (b->index_b == max_index)
				pa(&a, &b, 0);
			else
				get_it_to_top_and_pb(&a, &b, max_index, 1);
		}
		else
			get_it_to_top_and_pb(&a, &b, max_index, 2);
	}
	*stack_a = a;
	*stack_b = b;
}
