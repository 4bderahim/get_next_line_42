/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:31:34 by ael-krid          #+#    #+#             */
/*   Updated: 2024/01/22 17:31:37 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static void	join_the_two_strings(char *all, char const *s1, char const *s2)
{
	size_t	i;
	int		j;

	i = 0;
	if (s1 != 0)
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
	int		x;

	x = 0;
	if (s1 != NULL)
	{
		x = ft_strlen(s1);
	}
	string_len = x + ft_strlen(s2);
	allocated = (char *)malloc(string_len + 1);
	if (!allocated)
		return (NULL);
	join_the_two_strings(allocated, s1, s2);
	allocated[string_len] = '\0';
	free(s1);
	return (allocated);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
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
