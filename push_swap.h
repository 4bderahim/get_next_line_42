
#ifndef PUSH_SWAP
#define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>

typedef struct push_list{   
    struct push_list *next;
    struct push_list *prev;
    int val;
    int index;
    int index_b;
} p_list;
size_t	ft_strlen(const char *s);
void push_swap_sorting(p_list **stack_a, p_list **stack_b);
void handle_five_and_less(p_list **stack_a, p_list **stack_b, int arg_count);
int p_len(p_list *list);
void pa(p_list **list_a, p_list **list_b, int x);
void pb(p_list **list_a, p_list **list_b, int x);
void sa(p_list *head, int x);
void sb(p_list *head, int x);
void ss(p_list *list_a, p_list *list_b, int x);
void rra(p_list **a, int x);
void rrb(p_list **b_list, int x);
void rrr(p_list **b_list,p_list **a_list, int x);
void ra(p_list **a, int x);
void rb(p_list **b, int x);
void rr(p_list **b, p_list **a, int x);
p_list *p_new(int val);
p_list *p_last(p_list *node);
void p_addback(p_list **head, p_list *new);
void p_free(p_list *list);
int add_back_andcheck_max(p_list **main_a,long res, int sign , char *s);
long int p_atoi(char *s, p_list **main_a);
int argument_check(char **args, p_list **a, int argc);
char	*ft_strjoin(char *s1, char const *s2);
int check_input(p_list **main_a, p_list **main_b, char *pocket, char *buf);
int listening_to_stdin(p_list **main_a,p_list **main_b);

#endif
