#include "push_swap.h"

int indexing(p_list *list)
{
    int index;
    p_list *t;

    t = list;
    index = 0;
    while (t != NULL)
        {
            t->index = index;
            index++;
            t = t->next;
        }
    return index+1;
}
void index_stack_a(p_list *a)
{
    p_list *tmp;
    int i;

    i = 0;
    while (tmp != NULL)
    {
        tmp->index = i;
        tmp = tmp->next;
        i++;
    }
}
void list_mirror(p_list *a, p_list **b)
{
    p_list *tp;
    p_list *tp_b;

    tp  = a;
    tp_b = *b;
    while (tp != NULL)
    {
        p_addback(&tp_b, p_new(tp->val));
        tp = tp->next;
    }
    *b = tp_b;
}
void normal_sort(p_list **list)
{
    p_list *tmp;
    int v;
    int i;
      
    tmp = *list;
    i = indexing(tmp); 
    while (i > 0)
    {
        while (tmp != NULL)
        {
            tmp = tmp->next;
            if (tmp == NULL)
                break;
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
 void list_ranger(p_list **list_to_range, int ranges_count)
 {
    int list_count;
    int m;
    p_list *tmp;
    int i;
    
    list_count = (p_last(*list_to_range)->index) +1;
    tmp = *list_to_range;
    m = list_count / ranges_count ;
    i = 1;
    // if (list_count % ranges_count != 0)
    //     ranges_count -= 1;
    p_list *pp;
    pp = *list_to_range;

    while (pp != NULL)
    {
        printf("val=%d index=%d  \n",pp->val, pp->index);
        pp = pp->next;
    }
    while (i <= ranges_count )
    {
        //-----\}
        printf(" here !!!!   ++%d \n", i);
        tmp->range_id = i;
         if (m == tmp->index)
            i++;
        tmp = tmp->next;
    }
    
    m = list_count % ranges_count ;
    if (m != 0)
        {
            while (tmp != NULL)
                {
                    tmp->range_id = ranges_count+1;
                    tmp = tmp->next;
                }
        }
    
 }
void push_swap_sorting(p_list **stack_a, p_list **stack_b)
{
    p_list *range_array;
    range_array = NULL;
    list_mirror(*stack_a, &range_array);
    normal_sort(&range_array);
    index_stack_a(*stack_a);
    if (p_last(range_array)->index < 99)
        list_ranger(&range_array, 4);


    
}