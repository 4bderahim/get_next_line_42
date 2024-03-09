#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct push_list{
    struct push_list *next;
    struct push_list *prev;
    int val;
    int index;
} p_list;
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
    if (!node)
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
}
long int p_atoi(char *s)
{
    //int t;
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
 int check_args(char *s)
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
    return 1337;
}

int main(int argc, char **argv)
{
    p_list *main_a;
    int ii  = 1;
    main_a = NULL;
    
    if (argc > 1)
     {
        while (ii < argc)
            {
                if (!check_args(argv[ii]))
                    {
                        p_free(main_a);
                        write(1, "Error!", 6);
                        return 0;
                    }
                p_addback(&main_a, p_new(p_atoi(argv[ii])));
                ii++;
            }
     }
    p_list *p, *s, *cu;
    p = p_new(56);
    p_addback(&p, p_new(12));
    int i = 0;
    cu = main_a;
    while (i < 2)
    {
        printf("{%d\n", cu->val);
        cu = cu->next;
        i++;
    }
    system("leaks -q a.out");
    //p_free(p);
    //printf("%d", p->val);
}