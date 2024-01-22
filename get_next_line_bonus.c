#include "get_next_line.h"

static void	join_the_two_strings(char *all, char const *s1, char const *s2)
{
	size_t	i;
	int		j;

	i = 0;
	if (s1 !=0)
	{
		while (s1[i])
		{
			all[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		all[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*allocated;
	size_t	string_len;
	int x;
	x = 0;
	if (s1 != NULL)
		{
			x = ft_strlen(s1);
		}
	string_len = x + strlen(s2);
	allocated = (char *)malloc(string_len + 1);
	if (!allocated)
		return (NULL);
	join_the_two_strings(allocated, s1, s2);
	allocated[string_len] = '\0';
	
	free(s1);
	return (allocated);
}

char *line_join(char *pocket, int fd)
{
	char *buf;
	int cc;

	cc = 1;
	while (cc != 0)
	{
        buf = (char *) ft_calloc(1, BUFFER_SIZE+1);
		cc = read(fd ,buf, BUFFER_SIZE);
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
char *souvernire(char *pocket,char *rest)
{
	char *buf;
	int i;
	int j;

	j = 0;
	i = 0;
	if (pocket == NULL)
		return (NULL);
	if(pocket[0] == '\0')
            return (pocket);
	
	buf = ft_strjoin(NULL, rest+1);
	
	free(pocket);
	return (buf);
}
char *pocket_change(char *pocket)
{
	char *buf;
	int i;
	int j;
	
	i = 0;
	while(pocket[i] != '\n')
		i++;
	i++;
	buf = ft_calloc((i+1), 1);
	j = 0;
	while (j < i)
	{
		buf[j] = pocket[j];
		j++;
	}
	return (buf);
}
char *first_line(char *rest)
{
	char *buf;

	int i;
	i = 1;
	buf = ft_calloc(strlen(rest), 1);
	while(rest[i])
	{
		*buf = rest[i];
		i++;
		buf++;
	}
	return (buf);
}

char *get_next_line(int fd)
{
	static char *pocket[OPEN_MAX];
	char *new_line_check;
	char *buffer;

	if (fd < 0 || fd > OPEN_MAX)
		{
			free(pocket[fd]);
            pocket[fd] = NULL;
            return(NULL);
        }
    pocket[fd]  = line_join(pocket[fd], fd);
	if (pocket[fd] == NULL)
			return (NULL);
	new_line_check = ft_strchr(pocket[fd], '\n');
	if (new_line_check)
		buffer = pocket_change(pocket[fd]);
	else{
		buffer = ft_strjoin(pocket[fd], "");
		pocket[fd] = NULL;
		return buffer;
	}
	pocket[fd] = souvernire(pocket[fd], new_line_check);
	return (buffer);
}


