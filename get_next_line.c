/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:30:02 by ael-krid          #+#    #+#             */
/*   Updated: 2024/01/22 17:30:12 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*souv(char *pocket, char *rest)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (pocket == NULL)
		return (NULL);
	if (pocket[0] == '\0')
		return (pocket);
	buf = ft_strjoin(NULL, rest + 1);
	free(pocket);
	return (buf);
}

static char	*pocket_change(char *pocket)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	while (pocket[i] != '\n')
		i++;
	i++;
	buf = ft_calloc((i + 1), 1);
	j = 0;
	while (j < i)
	{
		buf[j] = pocket[j];
		j++;
	}
	return (buf);
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
