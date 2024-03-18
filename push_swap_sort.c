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
int check_range_id_in_stack_a(p_list *a, p_list *ranged, int id, char *top_bottom)
{
    p_list *tmp;
    p_list *tmp_ranged;

    tmp_ranged = get_range_start(ranged, id);
    tmp = a;
    if (top_bottom == "b")
        tmp = p_last(tmp);
    while (tmp_ranged->range_id == id)
    {
        while (tmp != NULL)
        {
            if (tmp->index == id)
                return (tmp->index);
            if (top_bottom == 'b')
                tmp = tmp->prev;
            else
                tmp = tmp->next;
        }
        tmp = a;
        tmp_ranged = tmp_ranged->next; 
    }
    return (-1);
}
int check_first_to_pb(int f_index, int s_index, int max_index)
{


    check wich to push return 1 if u want to oush to top first from bottom
    int middle_index_of_stack;

    middle_index_of_stack = max_index / 2;
    if (max_index -  f_index >= f_index)
        return (1)
}
void push_to_stack_b(p_list **stack_a, p_list **stack_b , p_list **ranged_list)
{
    p_list *ranged;
    int id;
    p_list *tmp_stack_a;
    tmp_stack_a = *stack_a;

    id = 0;
    ranged = *stack_a;
    while (tmp_stack_a != NULL)
    {

        if (check_range_id_in_stack_a(tmp_stack_a, ranged, id, "b") == -1)
            id++;

    }

}
void push_swap_sorting(p_list **stack_a, p_list **stack_b)
{
    p_list *range_array;
    range_array = NULL;
    list_mirror(*stack_a, &range_array);
    normal_sort(&range_array);
    index_stack_a(*stack_a, range_array);
    if (p_last(range_array)->index <= 99)
        list_ranger(&range_array, 5);
    else
        list_ranger(&range_array, 11);
    push_to_stack_b(stack_a, stack_b, &range_array);

    
}

22
45
6
8
7   6
3   22
4  











// p_list *p;

//     p = *stack_a;

//     while (p != NULL)
//     {
//         printf("val=%d | index=%d\n", p->val, p->index);
//         p = p->next;
//     }