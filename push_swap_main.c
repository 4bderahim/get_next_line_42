
#include "push_swap.h"

int	if_already_sorted(p_list *a)
{
	while (a->next != NULL)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	p_list	*main_a;
	p_list	*main_b;
	int		ii;
	int		arg_check;

	ii = 1;
	if (argc == 1)
		return (0);
	main_a = NULL;
	main_b = NULL;
	arg_check = argument_check(argv, &main_a, argc);
	if (arg_check == -1)
		return (0);
	if (arg_check == 0)
	{
		write(0, "Error\n", 6);
		return (0);
	}
	if (if_already_sorted(main_a))
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


// long int p_atoi(char *s, p_list **main_a)
// {
//     int i;
//     int sign = 1;
//     long res;

//     res = 0;
//     i = 0;
//     while(s[i] == ' ')
//     {
//         i++;
//         if (s[i] == 0)
//             break ;
//         if (s[i] != ' ')
//         {
//             while (s[i] != ' ' && s[i] != 0)
//             {
//                 if (s[i] == '+' || s[i] == '-')
//                 {
//                     if (s[i] == '-')
//                     sign *= -1;
//                     i++;
//                 }
//                 res  = (res * 10) + (s[i] - 48);
//                 i++;
//             }
//             p_addback(main_a, p_new(res * sign));
//             if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
//                 {
//                     free(s);
//                     return (-1);
//                 }
//             res = 0;
//             sign = 1;
//         }

//     }
//     free(s);
// 	return (res * sign);
// }
