#include "get_next_line.h"


// #ifndef BUFFER_SIZE
// #define 
// #endif

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
           
            if ((ret) && tmp[0] != 0)
            {
                if (ret[1] != '\0')
                    {
                        pocket = (char *) realloc(pocket, strlen(ret)+1);
                        pocket[strlen(ret)] = 0;
                        strlcat(pocket, ret, strlen(pocket));
                        //pocket[BUFFER_SIZE] = 0;
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
    if (cc == 0)
        return (0);
   // printf("reserve : %s\n", pocket);
    free(tmp);
    return (buf);
}






















// char *get_next_line(int fd)
// {
//     char *buf;
//     char *tmp;
//     static int stop;
//     char *ret;
//     if (write(fd, "", 0) < 0)   
//         return (0);
//     buf = calloc(1,20);
//     tmp = calloc(1,2);
//     int i = 0;
//     int j = 0;
//     ssize_t cc;

//     cc = 1;
//     while (tmp[0] != '\n' && cc != 0 && j < 20)
//         {
//             if (i >= stop && stop > 0)
//                 {
//                     cc = read(fd, tmp, 1);  
//                 }
//             else
//             {
//                 cc = read(fd, tmp, 1);  
                
//             }
//             if (tmp[0] != '\n')
//             {
//                 buf[j] = tmp[0];
//             }
//             i++;
//             j++;
//         }
//     if (cc == 0)
//         return (0);
//     stop = i;
//     free(tmp);
//     ret = get_buf(&buf);
//     free(buf);
//     return (ret);
// }