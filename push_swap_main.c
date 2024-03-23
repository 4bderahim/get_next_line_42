#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

p_list *p_new(int val)
{
    p_list *new;
    new = (p_list *) malloc(sizeof(p_list));
    new->val = val;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}
p_list *p_last(p_list *node)
{
    if (node == NULL)
        return (NULL);
    if (node->next == NULL)
            return node;
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}
void p_addback(p_list **head, p_list *new)
{
    p_list *tmp;
    if (!head)
         return ;
    tmp = p_last(*head);
    if (!tmp)
        {
            *head = new;
            return ;
        }
    tmp->next = new;
    new->prev = tmp;
}
long int p_atoi(char *s)
{
    int i;
    int sign = 1;
    long res;
    
    res = 0;
    i = 0;
    // while(s[i] == '\t' || s[i] == '\v'|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
    //     i++;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while (s[i] >= 48 && s[i] <= 57)
	{
		res = (res * 10) + (s[i] - 48);
		i++;
	}
    
	return (res * sign);
}
void p_free(p_list *list)
{

	p_list	*tmp;

	if (!list)
		return ;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
}

 int check_args(char *s, p_list *prev_node)
 {
    int i;
    long int num;
    i  = 0;

    while (s[i])
    {
        if (!(s[i] >= 48 && s[i] <= 57))
                if (!(s[i] == '+' || s[i] == '-'))
                        return 0;
        i++;
    }
    num = p_atoi(s);
    if (num > 2147483647 || num < -2147483648)
        return 0;
    if (prev_node != NULL)
        if (num > prev_node->val)
            return (1);
    return 13;
}


int main(int argc, char **argv)
{
    p_list *main_a;
    p_list *main_b;
    int ii  = 1;
    int next_mv;
    main_a = NULL;
    main_b = NULL;
    if (argc > 1)
     {
        while (ii < argc)
            {
                next_mv = check_args(argv[ii], p_last(main_a));
                if (!next_mv)
                    {
                        write(1, "Error!", 6);
                        return 0;
                    }
                p_addback(&main_a, p_new(p_atoi(argv[ii])));
                ii++;
            }
            if (argc < 7)
                handle_five_and_less(&main_a, &main_b, argc-1);
            else
                {
                    push_swap_sorting(&main_a, &main_b);
                }
     }
}



// if (next_mv == 1 && ii == argc)
            //     {
            //         system("leaks -q a.out");
            //         return 0;
            //     }







// if (tmp_b != NULL)
//     {
//         if (tmp_b->val < tmp_a->next->val)
//         {
//             if (tmp_b->val < tmp_a->val)
//                 pa(&tmp_a, &tmp_b);
//             else
//                 {
//                     pa(&tmp_a, &tmp_b);
//                     sa(tmp_a);
//                 }
//         }
//         else
//             {
//                 if (tmp_b->val > p_last(tmp_a)->val)
//                 {
//                     pa(&tmp_a, &tmp_b);
//                     ra(&tmp_a);
//                 }
//                 else if (tmp_b->val > p_last(tmp_a)->prev->val)
//                 {
//                     rra(&tmp_a);
//                     pa(&tmp_a, &tmp_b);
//                     ra(&tmp_a);
//                     ra(&tmp_a);
//                 }

//             }

//     }
