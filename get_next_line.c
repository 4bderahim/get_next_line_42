#include "get_next_line.h"


// #ifndef BUFFER_SIZE
// #define 
// #endif

size_t	ft_strlcat_next_line(char *dst, const char *src, int c)//, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	dstlen_increased;

	//dstlen = strlen(dst);
	//srclen = strlen(src);
	dstlen_increased = c;
	i = 0;
	while (src[i])
	{
        printf("noNE");
        
       // if (i == dstlen_increased )
		//    {
                
                dst[dstlen_increased] = src[i];
		        i++;
		        dstlen_increased++;
          //  }
	}
	dst[dstlen_increased] = '\0';
	return (dstlen + srclen);
}
static void	join_the_two_strings(char *all, char const *s1, char const *s2, int n)
{
	size_t	i;
	int		j;

	i = 0;
	while (s1[i])
	{
		all[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < n)
	{
		all[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char *s1, char *s2,int n)
{
	char	*allocated;
	size_t	string_len;
	string_len = strlen(s1) + strlen(s2);
	allocated = (char *)malloc(string_len + 1);
	if (!allocated)
		return (NULL);
    //printf("{{%s}}", j);
	join_the_two_strings(allocated, s1, s2,n);
	allocated[string_len] = '\0';
	return (allocated);
}

char *get_next_line(int fd)
{
    
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