#include "get_next_line.h"


// #ifndef BUFFER_SIZE
// #define 
// #endif

size_t	ft_strlcat_next_line(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	dstlen_increased;

	dstlen = strlen(dst);
	srclen = strlen(src);
	dstlen_increased = dstlen;
	i = 0;
	while (src[i] && dstlen_increased < dstsize - 1 && src[i] != '\n')
	{
		    dst[dstlen_increased] = src[i];
		    i++;
		    dstlen_increased++;
     
	}
	dst[dstlen_increased] = '\0';
	return (dstlen + srclen);
}


char *get_next_line(int fd)
{
    char *buf;
    char *tmp;
    static char *pocket;
    int i;
    int BUFFER_SIZE  = 12;
    char *ret;
    ssize_t cc;
    i = 1;
    cc = 1;
    buf = NULL;
    tmp = NULL; 
    while (cc != 0)
        {

            pocket = (char *)realloc(pocket , (BUFFER_SIZE*i)+1);
            pocket[BUFFER_SIZE*i] = 0;
            cc = read(fd, pocket, BUFFER_SIZE);
            ret = strchr(pocket, '\n');
             
            if ((ret))
            {
                tmp = (char *)realloc(tmp, strlen(ret)+1);
                tmp[strlen(ret)] = 0;
                
                buf = (char *)realloc(buf, ((int) ret)-((int) pocket));
                printf("\n\n\t\t\t\t%d\n\n\n", ((int) ret)-((int) pocket));
                buf[((int) ret)-((int) pocket)-1] = 0;
                printf("%s", buf);
                strncpy(buf, pocket, (((int) ret)-((int) pocket))+1);
                printf("\t\t\t>%s", buf);
                strncpy(pocket, ret+1, strlen(ret)+1);
                free(tmp);
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


