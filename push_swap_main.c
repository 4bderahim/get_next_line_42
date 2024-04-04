/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:51:22 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:51:24 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_three(t_list **main_a)
{
	t_list	*a;

	a = *main_a;
	if (a->val > a->next->next->val && a->next->val > a->val)
		ra(&a, 0);
	if (a->val < a->next->next->val && a->next->next->val < a->next->val)
	{
		sa(a, 0);
		ra(&a, 0);
	}
	if (a->val > a->next->val && a->val < a->next->next->val)
		sa(a, 0);
	if (a->next->val < a->next->next->val && a->next->next->val < a->val)
		ra(&a, 0);
	if (a->val > a->next->val && a->next->val > a->next->next->val)
	{
		sa(a, 0);
		rra(&a, 0);
	}
	*main_a = a;
}

int	if_already_sorted(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

void	handle_five_and_less(t_list **stack_a, t_list **stack_b, int arg_count)
{
	if (arg_count == 2)
	{
		if ((*stack_a)->val > (*stack_a)->next->val)
			sa(*stack_a, 0);
	}
	else if (arg_count == 3)
		handle_three(stack_a);
	else
		sort_five(stack_a, stack_b, arg_count);
}

void	sort_(t_list **main_a, t_list **main_b)
{
	if (p_len(*main_a) <= 5)
		handle_five_and_less(main_a, main_b, p_len(*main_a));
	else
		push_swap_sorting(main_a, main_b);
}

int	main(int argc, char **argv)
{
	t_list	*main_a;
	t_list	*main_b;
	int		ii;
	int		arg_check;

	ii = 1;
	if (argc == 1)
		return (0);
	main_a = NULL;
	main_b = NULL;
	arg_check = argument_check(argv, &main_a, argc);
	if (arg_check == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (if_already_sorted(main_a))
		return (0);
	else
		sort_(&main_a, &main_b);
	return (0);
}
