#include "push_swap.h"

int	check_instruction(char *n)
{
	char	*defs;
	int		i;

	defs = "pa\npb\nsa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	while (*defs)
	{
		i = 0;
		if (*defs == n[0])
		{
			while (n[i])
			{
				if (*(defs + i) == n[i])
				{
					if (n[i] == '\n')
						return (1);
				}
				i++;
			}
		}
		defs++;
	}
	return (0);
}

void	other_instructions(p_list **main_a, p_list **main_b, char *str)
{
	if (str[0] == 'r' && str[1] == 'r')
	{
		if (str[2] == 'a')
			rra(main_a, 1);
		if (str[2] == 'b')
			rrb(main_b, 1);
		if (str[2] == 'r')
			rrr(main_b, main_a, 1);
	}
}

int	do_instruction(p_list **a, p_list **b, char *str)
{
	if (check_instruction(str) == 0)
		return (0);
	if (str[2] == '\n')
	{
		if (str[0] == 'p' && str[1] == 'a')
			pa(a, b, 1);
		if (str[0] == 'p' && str[1] == 'b')
			pb(a, b, 1);
		if (str[0] == 's' && str[1] == 'a')
			sa(*a, 1);
		if (str[0] == 's' && str[1] == 'b')
			sb(*b, 1);
		if (str[0] == 's' && str[1] == 's')
			ss(*a, *b, 1);
		if (str[0] == 'r' && str[1] == 'a')
			ra(a, 1);
		if (str[0] == 'r' && str[1] == 'b')
			rb(b, 1);
		if (str[0] == 'r' && str[1] == 'r')
			rr(b, a, 1);
	}
	else
		other_instructions(a, b, str);
	return (1);
}

int	check_input(p_list **main_a, p_list **main_b, char *pocket, char *buf)
{
	if (ft_strlen(pocket) < 3)
	{
		free(pocket);
		free(buf);
		return (0);
	}
	if (!do_instruction(main_a, main_b, pocket))
	{
		free(pocket);
		free(buf);

		return (0);
	}
	return (1);
}