/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:14:28 by ael-krid          #+#    #+#             */
/*   Updated: 2024/04/04 03:14:30 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct push_list
{
	struct push_list	*next;
	struct push_list	*prev;
	int					val;
	int					index;
	int					index_b;
}						t_list;
int						is_empty_str(char *str);
size_t					ft_strlen(const char *s);
void					handle_three(t_list **main_a);
void					sort_five(t_list **tmp_a, t_list **tmp_b, int count);
void					index_stack_a(t_list *a, t_list *ranged_lst);
void					normal_sort(t_list **list);
void					push_to_a(t_list **stack_a, t_list **stack_b);
void					push_swap_sorting(t_list **stack_a, t_list **stack_b);
void					handle_five_and_less(t_list **stack_a, t_list **stack_b,
							int arg_count);
int						p_len(t_list *list);
void					pa(t_list **list_a, t_list **list_b, int x);
void					pb(t_list **list_a, t_list **list_b, int x);
void					sa(t_list *head, int x);
void					sb(t_list *head, int x);
void					ss(t_list *list_a, t_list *list_b, int x);
void					rra(t_list **a, int x);
void					rrb(t_list **b_list, int x);
void					rrr(t_list **b_list, t_list **a_list, int x);
void					ra(t_list **a, int x);
void					rb(t_list **b, int x);
void					rr(t_list **b, t_list **a, int x);
t_list					*p_new(int val);
t_list					*p_last(t_list *node);
void					p_addback(t_list **head, t_list *new);
void					p_free(t_list *list);
int						add_back_andcheck_max(t_list **main_a, long res,
							int sign, char *s);
long int				p_atoi(char *s, t_list **main_a);
int						argument_check(char **args, t_list **a, int argc);
char					*ft_strjoin(char *s1, char const *s2);
int						check_input(t_list **main_a, t_list **main_b,
							char *pocket, char *buf);
int						listening_to_stdin(t_list **main_a, t_list **main_b);
#endif
