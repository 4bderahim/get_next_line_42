#include "push_swap.h"

int p_len(p_list *list)
{
    int count;
    count = 1;

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
    write(1, "sa\n", 3);
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
     printf("rra");
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
     printf("rrb");
}
void rrr(p_list **b_list,p_list **a_list)
{
    p_list *last_b;
    p_list *last_a;
    p_list *a;
    p_list *b;

    if (b == NULL || b == NULL)
        return ;
    b = *b_list;
    a = *a_list;
    last_a = p_last(a);
    last_a->next = a;
    last_a->prev->next = NULL;
    last_a->prev = NULL;
    last_a->next->prev = last_a;
    *a_list = last_a;
    last_b = p_last(b);
    last_b->next = b;
    last_b->prev->next = NULL;
    last_b->prev = NULL;
    last_b->next->prev = last_b;
    *b_list = last_b;
     printf("rrr");

}
void pa(p_list **list_a, p_list **list_b)
{
    p_list *tmp_a;
    p_list *tmp_b;
    if (*list_b == NULL)
        return ;
    // if list_a is NULL; !!!!
    tmp_a = *list_a;
    tmp_b =  *list_b;
    
    if (tmp_b->next != NULL)
    {
        tmp_b = tmp_b->next;
        tmp_b->prev->next = tmp_a;
        tmp_a->prev = tmp_b->prev;
        tmp_b->prev = NULL;
        tmp_a = tmp_a->prev;
        tmp_a->prev = NULL;
    }
    else
    {
        tmp_a->prev = tmp_b;
        tmp_b->next = tmp_a;
        tmp_a = tmp_a->prev;
        tmp_a->prev = NULL;
        tmp_b = NULL;
    }
    *list_a = tmp_a;
    *list_b = tmp_b;
     printf("pa");
}

void pb(p_list **list_a, p_list **list_b)
{
    p_list *tmp_a;
    p_list *tmp_b;
    if (*list_a == NULL)
        return ;
    
    tmp_a = *list_a;
    tmp_b =  *list_b;
    if (tmp_b == NULL)
    {
        //tmp_p = *list;
        tmp_b = tmp_a;
        tmp_a = tmp_a->next;
        tmp_a->prev = NULL;
        tmp_b->next = NULL;
        tmp_b->prev = NULL;
    }
    else{
        if (tmp_a->next == NULL)
            {
                tmp_a->next = tmp_b;
                tmp_a->next->prev = tmp_a;
                tmp_a->prev = NULL;
                tmp_b = tmp_a;
                tmp_a = NULL;
            }
        else
        {
            tmp_a = tmp_a->next;
            tmp_a->prev->next = tmp_b;
            tmp_b->prev = tmp_a->prev;
            tmp_a->prev = NULL;
            tmp_b = tmp_b->prev;
            tmp_b->prev = NULL;
        }
    }
    *list_a = tmp_a;
    *list_b = tmp_b;
    printf("pb\n");
}


void ra(p_list **a)
{
    p_list *lst_a;
    p_list *last;
    lst_a = *a;
    last = p_last(lst_a);
    last->next = lst_a;
    lst_a = lst_a->next;
    lst_a->prev = NULL;
    last->next->next = NULL;
    last->next->prev = last;
    *a = lst_a;
     printf("ra\n");
}
void rb(p_list **b)
{
    p_list *lst_b;
    p_list *last;

    if (*b == NULL)
        return ;
    lst_b = *b;
    last = p_last(lst_b);
    last->next = lst_b;
    lst_b = lst_b->next;
    lst_b->prev = NULL;
    last->next->next = NULL;
    last->next->prev = last;
    *b = lst_b;
     printf("rb\n");
}


void rr(p_list **b, p_list **a)
{
    p_list *lst_b;
    p_list *last;
    p_list *lst_a;


    if (*b == NULL || *a == NULL)
        return ;
    lst_a = *a;
    last = p_last(lst_a);
    last->next = lst_a;
    lst_a = lst_a->next;
    lst_a->prev = NULL;
    last->next->next = NULL;
    last->next->prev = last;
    *a = lst_a;

    lst_b = *b;
    last = p_last(lst_b);
    last->next = lst_b;
    lst_b = lst_b->next;
    lst_b->prev = NULL;
    last->next->next = NULL;
    last->next->prev = last;
    *b = lst_b;
    printf("rr\n");
}


