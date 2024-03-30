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
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != ((char)c))
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*all;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
	{
		all = (char *)malloc(count * size);
		all[count * size] = 0;
		return (all);
	}
	all = (char *)malloc(count * size);
	if (!all)
		return (NULL);
	while (i < (count * size))
	{
		all[i] = '\0';
		i++;
	}
	return (all);
}

int check_instruction(char *n)
{
    char *defs;
    int i;

    i = 0;
    defs = "pa\npb\nsa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\n";
    while (*defs)
    {
        if (*defs == n[0])
            {
               while (n[i])
               {
                    if(*(defs+i) == n[i])
                        i++;
                    else
                        {
                            i = 0;
                            break;
                        }
               } 
               if (i != 0)
                return (1);
            }
        defs++;
    }
    return (0);
}
void other_instructions(p_list **main_a,p_list **main_b, char *str)
{
    if (str[0] == 'r' && str[1] == 'r')
        {
            if (str[2] == 'a')
                rra(main_a, 1);
            if (str[2] == 'b')
                rrb(main_b, 1);
            if (str[2] == 'r')
                rrr(main_b, main_a, 1);
        }
}
int do_instruction(p_list **a, p_list **b, char *str)
{
    if (check_instruction(str) == 0)
        return (0);
    if (str[2] == '\n')
        {
            if (str[0] == 'p' && str[1] == 'a')
                pa(a, b, 1);
            if (str[0] == 'p' && str[1] == 'b')
                {
                    pb(a, b, 1);
                }
            if (str[0] == 's' && str[1] == 'a')
                sa(*a, 1);
            if (str[0] == 's' && str[1] == 'b')
                sb(*b, 1);
            if (str[0] == 's' && str[1] == 's')
                ss(*a, *b, 1);
            if (str[0] == 'r' && str[1] == 'a')
                ra(a, 1);
            if (str[0] == 'r' && str[1] == 'b')
                rb(b, 1);
            if (str[0] == 'r' && str[1] == 'r')
                rr(b, a, 1);
        }
    else
        other_instructions(a, b, str);
    return (1);
}
int listening_to_stdin(p_list **main_a,p_list **main_b)
{
    p_list *p;
    char	*buf;
    char *pocket;
	int		cc;
    int buffz;

    buffz = 4;
    pocket = (char *) malloc(1);
    pocket[0] = 0;
    cc = 1;
    while (cc != 0)
	{
		buf = (char *)ft_calloc(1, buffz + 1);
		cc = read(0, buf, buffz);
		if (cc == -1 || (cc == 0))
		{
            printf("\n\n###\n\n\n");
			free(buf);
			return (0);
		}
        printf("\t\t\t[%s]\n\n", buf);
		if (buf[0] == '\n' || ft_strlen(buf) < 3)
		{
			free(buf);
            break;
		}
        if (buf[2] == '\n' || buf[3] == '\n')
                {
                    if (!do_instruction(main_a, main_b, buf))
                        {
                            free(buf);
                            break;
                        }
                }
        
    }
    p = *main_a;
    while (p != NULL)
        {
            printf("\t[%d]\n", p->val);
            p = p->next;
        }
    return (1);
}
int main(int argc, char **argv)
{
	p_list *main_a;
    p_list *main_b;
	int arg_check;

     
    main_a = NULL;
    main_b = NULL;
	
    
    if (argc > 1)
        {
            arg_check = argument_check(argv, &main_a, argc);
            if (arg_check == -1)
                return (0);
            if (arg_check == 0)
            {
                write(0, "Error\n" ,6);
                return (0);
            }
        }
	listening_to_stdin(&main_a, &main_b);
	return (0);
}





















// char	*line_join(char *pocket, int fd)
// {
// 	char	*buf;
// 	int		cc;

// 	cc = 1;
// 	while (cc != 0)
// 	{
// 		buf = (char *)ft_calloc(1, BUFFER_SIZE + 1);
// 		cc = read(fd, buf, BUFFER_SIZE);
// 		if (cc == -1 || ((cc == 0) && (!pocket || !pocket[0])))
// 		{
// 			free(pocket);
// 			free(buf);
// 			return (NULL);
// 		}
// 		pocket = ft_strjoin(pocket, buf);
// 		if (ft_strchr(pocket, '\n'))
// 		{
// 			free(buf);
// 			return (pocket);
// 		}
// 		free(buf);
// 	}
// 	return (pocket);
// }

// char	*first_line(char *rest)
// {
// 	char	*buf;
// 	int		i;

// 	i = 1;
// 	buf = ft_calloc(ft_strlen(rest), 1);
// 	while (rest[i])
// 	{
// 		*buf = rest[i];
// 		i++;
// 		buf++;
// 	}
// 	return (buf);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*pocket;
// 	char		*new_line_check;
// 	char		*buffer;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 	{
// 		free(pocket);
// 		return (NULL);
// 	}
// 	pocket = line_join(pocket, fd);
// 	if (pocket == NULL)
// 		return (NULL);
// 	new_line_check = ft_strchr(pocket, '\n');
// 	if (new_line_check)
// 		buffer = pocket_change(pocket);
// 	else
// 	{
// 		buffer = ft_strjoin(pocket, "");
// 		pocket = NULL;
// 		return (buffer);
// 	}
// 	pocket = souv(pocket, new_line_check);
// 	return (buffer);
// }