#include "push_swap.h"

void handle_three(p_list **main_a)
{
    p_list *a;

    a = *main_a;
    if (a->val > a->next->next->val && a->next->val > a->val)
        ra(&a, 0);
    if (a->val < a->next->next->val && a->next->next->val < a->next->val)
    {
        sa(a, 0);
        ra(&a, 0);
    }
    if (a->val > a->next->val && a->val < a->next->next->val)
        sa(a, 0);
    if (a->next->val < a->next->next->val && a->next->next->val < a->val)        
        ra(&a, 0);
    if (a->val > a->next->val && a->next->val > a->next->next->val)
        {
            sa(a, 0);
            rra(&a, 0);
        }
    *main_a = a;
}
void push_last_value_in_b_to_a(p_list **tmp_a, p_list **tmp_b)
{
    if ((*tmp_b)->val > p_last(*tmp_a)->val)
    {
        pa(tmp_a, tmp_b, 0);
        ra(tmp_a, 0);
    }
    else if ((*tmp_b)->val > p_last(*tmp_a)->prev->val)
    {
        rra(tmp_a, 0);
        pa(tmp_a, tmp_b, 0);
        ra(tmp_a, 0);
        ra(tmp_a, 0);
    }
    else
    {
        ra(tmp_a, 0);
        pa(tmp_a, tmp_b, 0);
        sa(*tmp_a, 0);
        rra(tmp_a, 0);
    }
}
void push_last_b_value(p_list **tmp_a, p_list **tmp_b)
{
    if ((*tmp_b)->val > (*tmp_a)->next->val)
            push_last_value_in_b_to_a(tmp_a, tmp_b);
    else
    {
        if ((*tmp_b)->val < (*tmp_a)->val)
            pa(tmp_a, tmp_b, 0);
        else
        {
            pa(tmp_a, tmp_b, 0);
            sa(*tmp_a, 0);
        }
    }
}
void rraparara(p_list **tmp_a,p_list **tmp_b )
{
    rra(tmp_a, 0);
    pa(tmp_a, tmp_b, 0);
    ra(tmp_a, 0);
    ra(tmp_a, 0);
}
void sort_five(p_list **tmp_a ,p_list **tmp_b, int count)
{
    pb(tmp_a, tmp_b, 0);
    if (count == 5)
        pb(tmp_a, tmp_b, 0);
    handle_three(tmp_a);
    if ((*tmp_b)->val < (*tmp_a)->val)
        pa(tmp_a, tmp_b, 0);
    else if ((*tmp_b)->val < (*tmp_a)->next->val)
    {
        pa(tmp_a, tmp_b, 0);
        sa(*tmp_a, 0);
    }
    else
    {
        if ((*tmp_b)->val < p_last(*tmp_a)->val)
            rraparara(tmp_a, tmp_b);
        else
        {
            pa(tmp_a, tmp_b, 0);
            ra(tmp_a, 0);
        }
    }
    if (*tmp_b != NULL)
        push_last_b_value(tmp_a, tmp_b);
}
void handle_five_and_less(p_list **stack_a, p_list **stack_b, int arg_count)
{
    
    if (arg_count == 2)
        {
            if ((*stack_a)->val > (*stack_a)->next->val)
                 sa(*stack_a, 0);
        }
    else if (arg_count == 3)
        handle_three(stack_a);
    else
        sort_five(stack_a, stack_b, arg_count);
}