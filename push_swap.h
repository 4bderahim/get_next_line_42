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
} p_list;
int p_len(p_list *list);
void pa(p_list **list_a, p_list **list_b);
void pb(p_list **list_a, p_list **list_b);
void sa(p_list *head);
void sb(p_list *head);
void ss(p_list *list_a, p_list *list_b);
void rra(p_list **a);
void rrb(p_list **b_list);
p_list *rrr(p_list *b, p_list *a);
// p_list *ra(p_list *a);
// p_list *ra(p_list *b);
p_list *p_last(p_list *node);
#endif
