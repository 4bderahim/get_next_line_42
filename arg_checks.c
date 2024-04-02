#include "push_swap.h"

int	check_full_arg_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57) && str[i] != ' ')
		{
			if (str[i] == '+' || str[i] == '-')
			{
				if (!(str[i + 1] >= 48 && str[i + 1] <= 57))
					return (0);
				if ((str[i - 1] >= 48 && str[i - 1] <= 57))
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}
char	*full_line(char **argv, int argc)
{
	int		i;
	char	*str;
	char	*str1;

	if (argc == 0)
		return (NULL);
	i = 1;
	str = (char *)malloc(1);
	str[0] = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			free(str);
			return (NULL);
		}
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	if (check_full_arg_line(str) == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
int	check_dups(p_list *a, int value)
{
	if (a->next == NULL)
		return (1);
	a = a->next;
	while (a != NULL)
	{
		if (a->val == value)
			return (0);
		a = a->next;
	}
	return (1);
}
int	check_duplicates(p_list *a)
{
	while (a != NULL)
	{
		if (!check_dups(a, a->val))
			return (0);
		a = a->next;
	}
	return (1);
}
int	argument_check(char **args, p_list **a, int argc)
{
	char	*line;

	line = full_line(args, argc - 1);
	if (!line)
	{
		return (0);
	}
	if (p_atoi(line, a) == -1)
		return (-1);
	if (check_duplicates(*a) == 0)
	{
		return (0);
	}
	return (1);
}

// int if_already_sorted_but_in_reverse(p_list *a)
// {
//     a = p_last(a);
//      while (a->prev != NULL)
//     {
//         if (a->val > a->prev->val)
//             return (1);
//         a = a->prev;
//     }
//     return (0);
// }