/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sort_and_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:51:37 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 02:51:39 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexing(t_list *list)
{
	int		index;
	t_list	*t;

	t = list;
	index = 0;
	while (t != NULL)
	{
		t->index = index;
		index++;
		t = t->next;
	}
	return (index + 1);
}

int	index_from_range(t_list *ranged_list, int value)
{
	t_list	*tmp;

	tmp = ranged_list;
	while (tmp != NULL)
	{
		if (tmp->val == value)
			break ;
		tmp = tmp->next;
	}
	return (tmp->index);
}

void	index_stack_a(t_list *a, t_list *ranged_lst)
{
	t_list	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		tmp->index = index_from_range(ranged_lst, tmp->val);
		tmp = tmp->next;
	}
}

void	normal_sort(t_list **list)
{
	t_list	*tmp;
	int		v;
	int		i;

	tmp = *list;
	i = indexing(tmp);
	while (i > 0)
	{
		while (tmp != NULL)
		{
			tmp = tmp->next;
			if (tmp == NULL)
				break ;
			if (tmp->prev->val > tmp->val)
			{
				v = tmp->prev->val;
				tmp->prev->val = tmp->val;
				tmp->val = v;
			}
		}
		tmp = *list;
		i--;
	}
}
