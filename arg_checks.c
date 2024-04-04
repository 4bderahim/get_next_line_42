/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:50:47 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:50:50 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

char	*full_line(char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = (char *)malloc(1);
	str[0] = 0;
	while (argv[i])
	{
		if (is_empty_str(argv[i]) || argv[i][0] == '\0')
		{
			free(str);
			return (NULL);
		}
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	if (check_full_arg_line(str) == 0 || i == -111)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	check_dups(t_list *a, int value)
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

int	check_duplicates(t_list *a)
{
	while (a != NULL)
	{
		if (!check_dups(a, a->val))
			return (0);
		a = a->next;
	}
	return (1);
}

int	argument_check(char **args, t_list **a, int argc)
{
	char	*line;

	if (argc < 2)
		return (0);
	line = full_line(args);
	if (!line)
		return (0);
	if (p_atoi(line, a) == -1 || check_duplicates(*a) == 0)
		return (0);
	return (1);
}
