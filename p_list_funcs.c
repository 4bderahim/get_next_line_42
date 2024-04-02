#include "push_swap.h"

p_list	*p_new(int val)
{
	p_list	*new;

	new = (p_list *)malloc(sizeof(p_list));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

p_list	*p_last(p_list *node)
{
	if (node == NULL)
		return (NULL);
	if (node->next == NULL)
		return (node);
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}
void	p_addback(p_list **head, p_list *new)
{
	p_list	*tmp;

	if (!head)
		return ;
	tmp = p_last(*head);
	if (!tmp)
	{
		*head = new;
		return ;
	}
	tmp->next = new;
	new->prev = tmp;
}

void	p_free(p_list *list)
{
	p_list	*tmp;

	if (!list)
		return ;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
}

int	add_back_andcheck_max(p_list **main_a, long res, int sign, char *s)
{
	p_addback(main_a, p_new(res * sign));
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
	{
		free(s);
		return (-1);
	}
	return (1);
}