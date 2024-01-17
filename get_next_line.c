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
			
			x = strlen(s1);
		}
	
	string_len = x + strlen(s2);
	allocated = (char *)malloc(string_len + 1);
	if (!allocated)
		return (NULL);
	join_the_two_strings(allocated, s1, s2);
	allocated[string_len] = '\0';
	return (allocated);
}
char *line_join(char *pocket, int fd)
{
	
	char *buf;
	int cc;
	char *check;
	char *tmp;
	buf = (char *) calloc(1, BUFFER_SIZE+1);
	cc = 1;
	while (cc != 0)
	{
		cc = read(fd ,buf, BUFFER_SIZE);
		pocket = ft_strjoin(pocket, buf);
		tmp = pocket;
		free(pocket);
		check = ft_strchr(buf, '\n');
		if (check)
		{
			free(buf);
			return (pocket);
		}
		if (cc == -1)
			return (NULL);
	}
	free(buf);
	return (pocket);
}

// char *line_join(char *pocket, int fd)
// {
	
// 	char *buf;
// 	int cc;
// 	char *check;

// 	buf = (char *) calloc(1, BUFFER_SIZE+1);
// 	cc = 1;
// 	while (cc != 0)
// 	{
// 		cc = read(fd ,buf, BUFFER_SIZE);
// 		pocket = ft_strjoin(pocket, buf);
// 		check = ft_strchr(buf, '\n');
// 		if (check)
// 		{
// 			free(buf);
// 			return (pocket);
// 		}
// 		if (cc == -1)
// 			return (NULL);
// 	}
// 	free(buf);
// 	return (pocket);
//     }
char *get_next_line(int fd)
{
	static char *pocket;
	char *new_line_check;
	char *buffer;
	int i;
    pocket  = line_join(pocket, fd);
	if (fd < 0)
		return(NULL);
	if (*pocket == '\0')
				return (NULL);
	new_line_check = ft_strchr(pocket, '\n');
	if (new_line_check)
	{
		if (new_line_check[1] == '\0')
			{
				buffer = pocket;
				buffer = ft_strjoin("", pocket);
				buffer[ft_strlen(pocket)-1] = 0;
				pocket = NULL;
				free(pocket);
			}
		else
		{
			buffer = (char *) ft_calloc(1, (((long) new_line_check)-((long) pocket))+1);
			i =0;
			while(pocket[i] != '\n')
			{
				buffer[i] = pocket[i];
				i++;
			}
			pocket = ft_strjoin("", new_line_check+1);
		}
		return (buffer);
	}
    return (NULL);
}
























// char *get_next_line(int fd)
// {
//     char *buf;
//     char *tmp;
//     static char *pocket;
//     int i;
//     int BUFFER_SIZE  = 12;
//     char *ret;
//     ssize_t cc;
//     i = 1;
//     cc = 1;
//     buf = NULL;
//     while (cc != 0)
//         {
//            // printf("\t\t\t{{%s}}\n", pocket);
//             if (pocket != NULL)
//             {
                
//                 ret = strchr(pocket, '\n');
//                 pocket = (char *)realloc(pocket , (BUFFER_SIZE*i)+1);
//                 pocket[BUFFER_SIZE*i] = 0;
//                 if (ret)
//                     {
                        
//                            buf  = ft_strjoin("", pocket, (((int) ret)-((int) pocket))+1);
//                            return (buf);
//                     } 
//               //  buf = ft_strjoin("", pocket, strlen(pocket));
//                // pocket = NULL;
//                 //return (buf);
//             }
            
//             pocket = (char *)realloc(pocket , (BUFFER_SIZE*i)+1);
//             pocket[BUFFER_SIZE*i] = 0;
//             tmp = (char *)realloc(tmp , (BUFFER_SIZE)+1);
//             tmp[BUFFER_SIZE] = 0;
            
//             cc = read(fd, tmp, BUFFER_SIZE);
//             ft_strlcat_next_line(pocket, tmp, BUFFER_SIZE*i);
//             free(tmp);
//             printf("%s", pocket);

//             printf("\t\t\t\t%lu\t-%s-\n", strlen(pocket),pocket);
//             ret = strchr(pocket, '\n');
//             printf("%s||||%lu\n\n", pocket, strlen(pocket));
//             if ((ret))
//             {
//                 buf  = ft_strjoin("", pocket,(((int) ret)-((int) pocket))+1);
//                // printf("#%s", buf);
//                 strncpy(pocket, ret+1, strlen(pocket));
                
//                 break;
//             }
//             i++;
//         }
//     return (buf);
// }