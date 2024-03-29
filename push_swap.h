#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef PUSH
#define PUSH

typedef struct push_list{   
    struct push_list *next;
    struct push_list *prev;
    int val;
    int index;
    //int range_id;
    int index_b;
} p_list;
void push_swap_sorting(p_list **stack_a, p_list **stack_b);
void handle_five_and_less(p_list **stack_a, p_list **stack_b, int arg_count);
//void sort_five(p_list **a , p_list **b, int count);
int p_len(p_list *list);
void pa(p_list **list_a, p_list **list_b);
void pb(p_list **list_a, p_list **list_b);
void sa(p_list *head);
void sb(p_list *head);
void ss(p_list *list_a, p_list *list_b);
void rra(p_list **a);
void rrb(p_list **b_list);
void rrr(p_list **b_list,p_list **a_list);
void ra(p_list **a);
void rb(p_list **b);
void rr(p_list **b, p_list **a);
p_list *p_new(int val);

p_list *p_last(p_list *node);
void p_addback(p_list **head, p_list *new);
void p_free(p_list *list);
int argument_check(char **args, p_list **a, int argc);
#endif


// check all cases in stack b to stack a elements befor pushing
