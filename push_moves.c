#include "push_swap.h"

int p_len(p_list *list)
{
    int count;
    count = 0;

    while (list != NULL)
    {
        list = list->next;
        count++;
    }
    return count;
}

void sa(p_list *list_a)
{
    int tmp;
    if (!list_a || !list_a->next)
        return ;
    tmp = list_a->next->val;
    list_a->next->val = list_a->val;
    list_a->val = tmp;
    tmp = list_a->next->index;
    list_a->next->index = list_a->index;
    list_a->index = tmp;
    write(1, "sa", 2);
}
void sb(p_list *list_b)
{
    int tmp;
    if (!list_b || !list_b->next)
        return ;
    tmp = list_b->next->val;
    list_b->next->val = list_b->val;
    list_b->val = tmp;
    tmp = list_b->next->index;
    list_b->next->index = list_b->index;
    list_b->index = tmp;
    write(1, "sb", 2);
}
void ss(p_list *list_a, p_list *list_b)
{
    sa(list_a);
    sb(list_b);
}
void rra(p_list **a_list)
{
    p_list *last;
    p_list *a;

    a = *a_list;
    if (a == NULL)
        return ;
    last = p_last(a);
    last->next = a;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next->prev = last;
    *a_list = last;
}
void rrb(p_list **b_list)
{
    p_list *last;
    p_list *b;

    b = *b_list;
    if (b == NULL)
        return ;
    last = p_last(b);
    last->next = b;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next->prev = last;
    *b_list = last;
}
// p_list *rrr(p_list **b)
// {

// }
void pa(p_list **list_a, p_list **list_b)
{
    p_list *tmp_a;
    p_list *tmp_b;
    if (*list_b == NULL)
        return ;
    // if list_a is NULL; !!!!
    tmp_a = *list_a;
    tmp_b =  *list_b;
    tmp_b = tmp_b->next;
    tmp_b->prev->next = tmp_a;
    tmp_a->prev = tmp_b->prev;
    tmp_b->prev = NULL;
    tmp_a = tmp_a->prev;
    tmp_a->prev = NULL;
    *list_a = tmp_a;
    *list_b = tmp_b;
}
void pb(p_list **list_a, p_list **list_b)
{
    p_list *tmp_a;
    p_list *tmp_b;
    if (*list_a == NULL)
        return ;
    
    tmp_a = *list_a;
    tmp_b =  *list_b;
    tmp_a = tmp_a->next;
    tmp_a->prev->next = tmp_b;
    tmp_b->prev = tmp_a->prev;
    tmp_a->prev = NULL;
    tmp_b = tmp_b->prev;
    tmp_b->prev = NULL;
    *list_a = tmp_a;
    *list_b = tmp_b;
}