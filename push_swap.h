#include <stdio.h>
#include <stdlib.h>


#ifndef PUSH
#define PUSH

typedef struct push_list{
    struct push_list *next;
    struct push_list *prev;
    int val;
    int index;
} p_list;
void sa(p_list *head);
#endif
