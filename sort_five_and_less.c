/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_less.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:52:35 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:52:37 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_last_value_in_b_to_a(t_list **tmp_a, t_list **tmp_b)
{
	if ((*tmp_b)->val > p_last(*tmp_a)->val)
	{
		pa(tmp_a, tmp_b, 0);
		ra(tmp_a, 0);
	}
	else if ((*tmp_b)->val > p_last(*tmp_a)->prev->val)
	{
		rra(tmp_a, 0);
		pa(tmp_a, tmp_b, 0);
		ra(tmp_a, 0);
		ra(tmp_a, 0);
	}
	else
	{
		ra(tmp_a, 0);
		pa(tmp_a, tmp_b, 0);
		sa(*tmp_a, 0);
		rra(tmp_a, 0);
	}
}

void	push_last_b_value(t_list **tmp_a, t_list **tmp_b)
{
	if ((*tmp_b)->val > (*tmp_a)->next->val)
		push_last_value_in_b_to_a(tmp_a, tmp_b);
	else
	{
		if ((*tmp_b)->val < (*tmp_a)->val)
			pa(tmp_a, tmp_b, 0);
		else
		{
			pa(tmp_a, tmp_b, 0);
			sa(*tmp_a, 0);
		}
	}
}

void	rraparara(t_list **tmp_a, t_list **tmp_b)
{
	rra(tmp_a, 0);
	pa(tmp_a, tmp_b, 0);
	ra(tmp_a, 0);
	ra(tmp_a, 0);
}

void	sort_five(t_list **tmp_a, t_list **tmp_b, int count)
{
	pb(tmp_a, tmp_b, 0);
	if (count == 5)
		pb(tmp_a, tmp_b, 0);
	handle_three(tmp_a);
	if ((*tmp_b)->val < (*tmp_a)->val)
		pa(tmp_a, tmp_b, 0);
	else if ((*tmp_b)->val < (*tmp_a)->next->val)
	{
		pa(tmp_a, tmp_b, 0);
		sa(*tmp_a, 0);
	}
	else
	{
		if ((*tmp_b)->val < p_last(*tmp_a)->val)
			rraparara(tmp_a, tmp_b);
		else
		{
			pa(tmp_a, tmp_b, 0);
			ra(tmp_a, 0);
		}
	}
	if (*tmp_b != NULL)
		push_last_b_value(tmp_a, tmp_b);
}
