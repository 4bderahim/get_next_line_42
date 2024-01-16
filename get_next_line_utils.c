//
#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
        int     i;

        i = 0;
        while (s[i] != ((char)c))
        {
                if (s[i] == '\0')
                        return (0);
                i++;
        }
        return ((char *)s + i);
}
size_t ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
char *ft_bzero(char *s, size_t n)
{
    size_t i;

    i = 0;
    while(i < n) 
    {
        s[i] = 0;
        i++;
    }
    return (s);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*all;
	size_t	tmp;

	if (count == 0 || size == 0)
	{
		all = (char *)malloc(count * size);
        all[count*size] = 0;
		return (all);
	}
	tmp = count * size;
	if ((tmp / size) != count)
		return (NULL);
    
	all = (char *)malloc(count * size);
	if (!all)
		return (NULL);
	return (ft_bzero(all, count * size));
}
