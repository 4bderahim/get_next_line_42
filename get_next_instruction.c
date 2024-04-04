/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:13:48 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 03:13:49 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_already_sorted(t_list *a)
{
	if (!a)
		return (0);
	while (a->next != NULL)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	make_decision(t_list *main_a, t_list *main_b)
{
	if (if_already_sorted(main_a) && main_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*main_a;
	t_list	*main_b;
	int		arg_check;

	main_a = NULL;
	main_b = NULL;
	if (argc == 1)
		return (0);
	if (argc >= 1)
	{
		arg_check = argument_check(argv, &main_a, argc);
		if (arg_check == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	listening_to_stdin(&main_a, &main_b);
	return (make_decision(main_a, main_b));
}
