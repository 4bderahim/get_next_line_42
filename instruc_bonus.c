#include "push_swap.h"

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

int	free_pocket_free_buf_return_z(char *buf, char *pocket, int x)
{
	free(pocket);
	free(buf);
	return (x);
}

int	hit_enter_but_no_inst(char *buf, char *pocket, int x)
{
	if (x == 1)
		return (free_pocket_free_buf_return_z(buf, pocket, 1));
	return (free_pocket_free_buf_return_z(buf, pocket, 0));
}
int(free_buf_pocket_ret_1(char *buf, char *pocket))
{
	free(pocket);
	free(buf);
	return (1);
}

int	listening_to_stdin(p_list **main_a, p_list **main_b)
{
	char *buf;
	char *pocket;
	int x;

	x = 0;
	pocket = (char *)ft_calloc(1, 1);
	buf = (char *)ft_calloc(1, 2);
	while (read(0, buf, 1) != 0)
	{
		pocket = ft_strjoin(pocket, buf);
		if (pocket[0] == '\n')
			return (hit_enter_but_no_inst(buf, pocket, x));
		if (buf[0] == '\n')
		{
			if (check_input(main_a, main_b, pocket, buf) == 0)
				return (0);
			else
			{
				free(pocket);
				pocket = (char *)ft_calloc(1, 1);
			}
		}
		x = 1;
	}
	return (free_buf_pocket_ret_1(buf, pocket));
}