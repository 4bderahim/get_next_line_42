#include "get_next_line.h"


// #ifndef BUFFER_SIZE
// #define 
// #endif

size_t	ft_strlcat_next_line(char *dst, const char *src, char c)//, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	dstlen_increased;

	dstlen = strlen(dst);
	srclen = strlen(src);
	dstlen_increased = dstlen;
	i = 0;
	while (src[i] || src[i] != c)
	{
		    dst[dstlen_increased] = src[i];
		    i++;
		    dstlen_increased++;
            printf("%zu", i);
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
    printf("{{%s}}", jj);
	join_the_two_strings(allocated, s1, s2,n);
	allocated[string_len] = '\0';
	return (allocated);
}

// void buf_pocket(char *buf, char *pocket, int length)
// {
    
// }
char *get_next_line(int fd)
{
    char *buf;
    char *tmp;
    static char *pocket;
    int i;
    int BUFFER_SIZE  = 12;
    char *ret;
    ssize_t cc;
    d\nf\d\ndgn\n
    i = 1;
    cc = 1;
    buf = NULL;
    while (cc != 0)
        {
            if (pocket != NULL)
            {
                ret = strchr(pocket, '\n');
                pocket = (char *)realloc(pocket , (BUFFER_SIZE*i)+1);
                pocket[BUFFER_SIZE*i] = 0;
                if (ret)
                    {
                           buf  = ft_strjoin("", pocket, (((int) ret)-((int) pocket))+1);
                           return (buf);
                    } 
                   
            }
            pocket = (char *)realloc(pocket , (BUFFER_SIZE*i)+1);
            pocket[BUFFER_SIZE*i] = 0;

            cc = read(fd, pocket, BUFFER_SIZE);
            //printf("[%s]\n", pocket);
            ret = strchr(pocket, '\n');
            if ((ret))
            {
             //   printf("[[%s||%d||%s",ret, ((int) ret)-((int) pocket),pocket);
                buf  = ft_strjoin("", pocket,(((int) ret)-((int) pocket))+1);
                printf("??%s\n", buf);
                strncpy(pocket, ret, strlen(ret));
                printf("\n\n\t%s", pocket);
                break;
            }
            i++;
        }
    return (buf);
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
//     tmp = NULL;
//     while (cc != 0)
//         {
//             tmp = (char *)realloc(tmp , (BUFFER_SIZE*i)+1);
//             buf = (char *)realloc(buf , (BUFFER_SIZE*i)+1);
//             tmp[BUFFER_SIZE*i] = 0;
//             buf[BUFFER_SIZE*i] = 0;
//             cc = read(fd, tmp, BUFFER_SIZE);
             
//             ret = strchr(tmp, '\n');
          
//             if (pocket != NULL)  
//             {
//                 strcpy(buf, pocket);
//                 printf("##%s||%s\n", pocket, buf);

//             }
             
//             if ((ret) && tmp[0] != 0)
//             {
//                 if (ret[1] != '\0')
//                     {
//                         pocket = (char *) realloc(pocket, strlen(ret)+1);
//                         pocket[strlen(ret)] = 0;
//                         // printf("{{{%s}}}\n", pocket);
//                         strlcat(pocket, ret+1, strlen(pocket));
//                         //printf("[[%s]]\n", );
//                         //strlcat(pocket, ret, strlen(pocket)); 
//                     }
//                 int i = 0;
//                 while(tmp[i] !='\n')//tmp != ret)
//                 {
//                     buf[i] = tmp[i];
//                     i++;
//                 }
//                 break;
//             }
//             i++;
//         }
//     // if (cc == 0)
//     //     return (0);
//     //if (cc == 0)
//     printf("\t\t\t[%s||%s]\n", buf, pocket);
//     //free(pocket);
//     free(tmp);
    
//     return (buf);
// }


