#include "push_swap.h"

char	*line_join(char *pocket, int fd)
{
	char	*buf;
	int		cc;

	cc = 1;
	while (cc != 0)
	{
		buf = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		cc = read(fd, buf, BUFFER_SIZE);
		if (cc == -1 || ((cc == 0) && (!pocket || !pocket[0])))
		{
			free(pocket);
			free(buf);
			return (NULL);
		}
		pocket = ft_strjoin(pocket, buf);
		if (ft_strchr(pocket, '\n'))
		{
			free(buf);
			return (pocket);
		}
		free(buf);
	}
	return (pocket);
}

char	*first_line(char *rest)
{
	char	*buf;
	int		i;

	i = 1;
	buf = ft_calloc(ft_strlen(rest), 1);
	while (rest[i])
	{
		*buf = rest[i];
		i++;
		buf++;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*pocket;
	char		*new_line_check;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(pocket);
		return (NULL);
	}
	pocket = line_join(pocket, fd);
	if (pocket == NULL)
		return (NULL);
	new_line_check = ft_strchr(pocket, '\n');
	if (new_line_check)
		buffer = pocket_change(pocket);
	else
	{
		buffer = ft_strjoin(pocket, "");
		pocket = NULL;
		return (buffer);
	}
	pocket = souv(pocket, new_line_check);
	return (buffer);
}
int main(int argc, char **argv)
{
	p_list *main_a;
    p_list *main_b;
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
	return (0);

}
