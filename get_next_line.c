#include "get_next_line.h"


// #ifndef BUFFER_SIZE
// #define 
// #endif
void hel()
{
    return;
}
void hel()
{
    return;
}
void hel()
{
    return;
}
size_t	ft_strlcat_next_line(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	dstlen_increased;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dstlen_increased = dstlen;
	i = 0;
	while (src[i] && dstlen_increased < dstsize - 1)
	{
        if (src[i] == '\n')
        {
		    dst[dstlen_increased] = src[i];
		    i++;
		    dstlen_increased++;
        }
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
            tmp = (char *)realloc(tmp , (BUFFER_SIZE*i)+1);
            buf = (char *)realloc(buf , (BUFFER_SIZE*i)+1);
            tmp[BUFFER_SIZE*i] = 0;
            buf[BUFFER_SIZE*i] = 0;
            cc = read(fd, tmp, BUFFER_SIZE);
             
            ret = strchr(tmp, '\n');
          
            if (pocket != NULL)  
            {
                strcpy(buf, pocket);
                printf("##%s||%s\n", pocket, buf);

            }
             
            if ((ret) && tmp[0] != 0)
            {
                if (ret[1] != '\0')
                    {
                        pocket = (char *) realloc(pocket, strlen(ret)+1);
                        pocket[strlen(ret)] = 0;
                        // printf("{{{%s}}}\n", pocket);
                        strlcat(pocket, ret+1, strlen(pocket));
                        //printf("[[%s]]\n", );
                        //strlcat(pocket, ret, strlen(pocket)); 
                    }
                int i = 0;
                while(tmp[i] !='\n')//tmp != ret)
                {
                    buf[i] = tmp[i];
                    i++;
                }
                break;
            }
            i++;
        }
    // if (cc == 0)
    //     return (0);
    //if (cc == 0)
    printf("\t\t\t[%s||%s]\n", buf, pocket);
    //free(pocket);
    free(tmp);
    
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


