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
    if (*s1 != 0)
        free(s1);
	join_the_two_strings(allocated, s1, s2);
	allocated[string_len] = '\0';

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
    i = 1;
    str = (char *) malloc(1);
    str[0] = 0;
    while (argv[i])
    {
        str = ft_strjoin(str, argv[i]);
        str = ft_strjoin(str, " ");
        i++;
    }
    
    if (check_full_arg_line(str) == 0)
        {
            write(1, "Error!", 6);
            return (NULL);
        }
    else
        {
            if (argc == 1)
                return NULL;
        }
    
    return str;
}
int check_args(char *s, p_list *prev_node)
 {
    int i;
    long int num;
    i  = 0;
    int check_stop;

    check_stop = 1;
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
    if (prev_node != NULL && check_stop != 1)
        {
            printf("%ld||%d\n", num, prev_node->val);
            if (num > prev_node->val)
                return (check_stop);
            else
                check_stop = 0;
        }
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
        //full_line(argv);
        while (ii < argc)
            {
                next_mv = check_args(argv[ii], p_last(main_a));
                if (full_line(argv, argc-1) == NULL)
                    return 0;
                else if (next_mv == 1 && p_len(main_a) == argc-2)
                    return 0;
                p_addback(&main_a, p_new(p_atoi(argv[ii])));
                ii++;
            }
            if (argc < 7)
                handle_five_and_less(&main_a, &main_b, argc-1);
            else
                push_swap_sorting(&main_a, &main_b);
     }
}
