#include "push_swap.h"

void sa(p_list *head)
{
    int tmp;
    if (!head || !head->next)
        return ;
    tmp = head->next->val;
    head->next->val = head->val;
    head->val = tmp;
    tmp = head->next->index;
    head->next->index = head->index;
    head->index = tmp;
}




