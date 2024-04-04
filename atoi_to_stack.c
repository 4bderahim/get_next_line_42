/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:52:12 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:52:14 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	atoi_(char *s, int *sign, int *i)
{
	long	res;

	res = 0;
	while (s[*i] != ' ' && s[*i] != 0)
	{
		if (s[*i] == '+' || s[*i] == '-')
		{
			if (s[*i] == '-')
				*sign *= -1;
			(*i)++;
		}
		res = (res * 10) + (s[*i] - 48);
		(*i)++;
	}
	return (res);
}

long int	p_atoi(char *s, t_list **main_a)
{
	int		i;
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (s[i] == ' ')
	{
		i++;
		if (s[i] == 0)
			break ;
		if (s[i] != ' ')
		{
			res = atoi_(s, &sign, &i);
			if (add_back_andcheck_max(main_a, res, sign, s) == -1)
				return (-1);
			res = 0;
			sign = 1;
		}
	}
	free(s);
	return (res * sign);
}
