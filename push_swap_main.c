
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
long int p_atoi(char *s, p_list **main_a)
{
    int i;
    int sign = 1;
    long res;
    
    res = 0;
    i = 0;
    while(s[i] == ' ')
    {
        i++;
        if (s[i] == 0)
            break;
        if (s[i] != ' ')
        {
            while (s[i] != ' ' && s[i] != 0)
            {
                if (s[i] == '+' || s[i] == '-')
                {
                    if (s[i] == '-')
                    sign *= -1;
                    i++;
                }
                res  = (res * 10) + (s[i] - 48);
                i++;
            }
            p_addback(main_a, p_new(res * sign));
            if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
                {
                    free(s);
                    return (-1);
                }
            res = 0;
            sign = 1;
        }
        
    }
    free(s);
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
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
static void	join_the_two_strings(char *all, char const *s1, char const *s2)
{
	size_t	i;
	int		j;

	i = 0;
	while (s1[i])
	{
		all[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		all[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*allocated;
	size_t	string_len;

	if (!s1 || !s1)
		return (NULL);
	string_len = ft_strlen(s1) + ft_strlen(s2);
	allocated = (char *)malloc(string_len + 1);
	if (!allocated)
		return (NULL);
    
	join_the_two_strings(allocated, s1, s2);
	allocated[string_len] = '\0';
    free(s1);
	return (allocated);
}
int check_full_arg_line(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (!(str[i] >= 48 && str[i] <= 57) && str[i] != ' ')
            {
                if (str[i] == '+' || str[i] == '-')
                    {
                        if (!(str[i+1] >= 48 && str[i+1] <= 57))
                            return (0);
                        if ((str[i-1] >= 48 && str[i-1] <= 57))
                            return (0);
                    }
                else
                    return 0;
            }
        i++;
    }
    return 1;
}
char *full_line(char **argv, int argc)
{
    int i;
    char *str;
    char *str1;
    if (argc == 0)
        return NULL;
    i = 1;
    str = (char *) malloc(1);
    str[0] = 0;
    while (argv[i])
    {
        if (argv[i][0] == '\0')
            {
                free(str);
                return (NULL);
            }
        str = ft_strjoin(str, " ");
        str = ft_strjoin(str, argv[i]);
        i++;
    }
    if (check_full_arg_line(str) == 0)
        {
            free(str);
            return (NULL);
        }
    return str;
}
int check_dups(p_list *a,int value)
{
    if (a->next == NULL)
        return (1);
    a = a->next;
    while (a != NULL)
    {
        if (a->val == value)
            return (0);
        a = a->next;
    }
    return (1);
}
int check_duplicates(p_list *a)
{
    
    while (a != NULL)
    {
        if (!check_dups(a, a->val))
            return (0);
        a =a->next;
    }
    return (1);
}
int if_already_sorted(p_list *a)
{
    while (a->next != NULL)
    {
        if (a->val > a->next->val)
            return (1);
        a = a->next;
    }
    return (0);
}
int if_already_sorted_but_in_reverse(p_list *a)
{
    a = p_last(a);
     while (a->prev != NULL)
    {
        if (a->val > a->prev->val)
            return (1);
        a = a->prev;
    }
    return (0);
}
void swap_reverse(p_list **aa)
{

    p_list *a;
    p_list *last;

    a = *aa;
    last = p_last(a);

    
    while (a != last)
     ra(&a)
     ;
    
}

int argument_check(char **args, p_list **a, int argc)
{
    char *line;

    line = full_line(args,  argc-1);
    if (!line)
        {
            return (0);
        }
    if (p_atoi(line, a) == -1)    
        return (-1);
    if (check_duplicates(*a) == 0)
        {
            return (0);
        }
    return (1);
}
int main(int argc, char **argv)
{
    p_list *main_a;
    p_list *main_b;
    int ii  = 1;
    int arg_check;

    
    if (argc == 1)  
        return (0);
    main_a = NULL;
    main_b = NULL;
    arg_check = argument_check(argv, &main_a, argc);
    if (arg_check == -1)
        return (0);
    if (arg_check == 0)
    {
        write(0, "Error\n" ,6);
        return (0);
    }
    if (if_already_sorted(main_a) == 0 )
        return (0);
    // if (if_already_sorted_but_in_reverse(main_a) == 0)
    //     swap_reverse(&main_a);
    else
    {
        if (p_len(main_a) <= 5)
            handle_five_and_less(&main_a, &main_b, p_len(main_a));
        else
            push_swap_sorting(&main_a, &main_b);
    }
}



