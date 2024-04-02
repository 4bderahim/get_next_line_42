#include "push_swap.h"

int	if_already_sorted(p_list *a)
{
	while (a->next != NULL)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	make_decision(p_list *main_a, p_list *main_b)
{
	if (if_already_sorted(main_a) && main_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int argc, char **argv)
{
	p_list	*main_a;
	p_list	*main_b;
	int		arg_check;

	main_a = NULL;
	main_b = NULL;
	if (argc >= 1)
	{
		arg_check = argument_check(argv, &main_a, argc);
		if (arg_check == -1)
			return (0);
		if (arg_check == 0)
		{
			write(0, "Error\n", 6);
			return (0);
		}
	}
	if (if_already_sorted(main_a))
		return (0);
	if (listening_to_stdin(&main_a, &main_b) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (make_decision(main_a, main_b));
}
