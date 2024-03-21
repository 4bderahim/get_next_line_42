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
int index_from_range(p_list *ranged_list, int value)
{
    p_list *tmp;

    tmp = ranged_list;
    while (tmp != NULL)
    {
        if (tmp->val == value)
            break;
        tmp  = tmp->next;
    }
    return (tmp->index);
}
void index_stack_a(p_list *a, p_list *ranged_lst)
{
    p_list *tmp;
    
    tmp = a;
    while (tmp != NULL)
    {
        tmp->index = index_from_range(ranged_lst, tmp->val);
        tmp = tmp->next;
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
    i = 1;
    m = list_count / ranges_count ;
    while (tmp != NULL)
    {
        tmp->range_id = i;
        if (tmp->index+1 == m)
        {
            if (m < (list_count / ranges_count) * ranges_count)
                {
                    m += list_count / ranges_count;
                    i++;
                }
        }
        tmp = tmp->next;
    }
 }
p_list *get_range_start(p_list *r, int id)
{
    p_list *tmp_ranged;

    tmp_ranged = r;
    while (tmp_ranged != NULL)
    {
        if (tmp_ranged->range_id == id)
            break;
        tmp_ranged = tmp_ranged->next;
    }
    return (tmp_ranged);
}
int check_range_id_in_stack_a(p_list *a, int id)
{
    p_list *tmp;

    tmp = a;
    
    while (tmp != NULL)
    {
        if (tmp->range_id == id)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
int is_from_range(int index,int range_id,  p_list *ranged_list)
{
    p_list *tmp;

    tmp = get_range_start(ranged_list, range_id);
    while (tmp != NULL && tmp->range_id == range_id)
    {
        if (tmp->index == index)
            {
                return(1);
            }
        tmp = tmp->next;
    }
    return (0);
}
void list_a_ranger(p_list **stack_a,p_list *range_array)
{

    p_list *tmp;
    p_list *tmp_r;
    tmp = *stack_a;
    tmp_r = range_array;
    while (tmp !=NULL)
    {
        while (tmp_r != NULL)
        {
            if (tmp_r->index == tmp->index)
                tmp->range_id = tmp_r->range_id;
            tmp_r = tmp_r->next;
        }
        tmp_r = range_array;
        tmp = tmp->next;
    }
}

void push_range_to_b(p_list **stack_a, p_list **stack_b, p_list *ranged_list, int id)
{
    p_list *a;
    p_list *b;
    int i;
    i = 0;
    int range_id;
    range_id = 15;
    a = *stack_a;
    b = *stack_b;
    p_list *pp;
    pp = *stack_a;
    while (a != NULL)
    {
        if (a->index > range_id)
           {
            ra(&a);
            
           } 
        else if(a->index >= i && a->index <= range_id)
        {
            pb(&a, &b);
            i++;
            range_id++;
        }
        else
        {
            pb(&a, &b);
            if (b->next != NULL)
                {
                    rb(&b);
                }
            i++;
            range_id++;
        }
        
    }
}

int get_max(p_list *b)
{
    int i;
    i = 0;
    b = b->next;
    while (b != NULL)
    {
        if (a->index > a->prev->index)
            i = a->index;
        a = a->next;
    }
    return (i);
}

void push_swap_sorting(p_list **stack_a, p_list **stack_b)
{
    
    p_list *a;
    p_list *p;
    int range_id;

    a = *stack_a;
    p = *stack_a;
   
    p_list *range_array;
    range_array = NULL;
    list_mirror(*stack_a, &range_array);
    normal_sort(&range_array);
    index_stack_a(*stack_a, range_array);
    if (p_last(range_array)->index <= 99)
        range_id = 15;
    else
        range_id = 25;

    list_ranger(&range_array, range_id);
    list_a_ranger(stack_a, range_array);
    
    push_range_to_b(stack_a, stack_b, range_array, range_id);
    // pp = *stack_a;
    //  printf("_++_+\n");
    // while (pp != NULL)
    // {
    //     printf("val=%d | index=%d range_id=%d\n", pp->val, pp->index, pp->range_id);
    //     pp = pp->next;
    // }
}





//  while (a != NULL)
//     {
//         if (check_range_id_in_stack_a(a, range_id, ranged_list) == -1)
//             {
//                 range_id++;
//             }
//         if (is_from_range(a->index, range_id, ranged_list))
//         {
//             printf("\t%d\n", a->val);
//             pb(&a, &b);
//             if (b->next != NULL)
//                 {
//                     if (b->val < b->next->val)
//                         rb(&b);
//                 }
//         }
//         else
//             ra(&a);
        

//         while (pp != NULL)
//         {
//             printf("val=%d | index=%d range_id=%d\n", pp->val, pp->index, pp->range_id);
//             pp = pp->next;
//         }
//         a = a->next;
//         //*stack_b = b;
//     }











