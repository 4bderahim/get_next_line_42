#include "get_next_line.h"


char *get_next_line(int fd)
{
    char *buf;
    char *tmp;
    static int stop;
    char *ret;
    if (write(fd, "", 0) < 0)   
        return (0);
    buf = calloc(1,20);
    tmp = calloc(1,2);
    int i = 0;
    int j = 0;
    ssize_t cc;

    cc = 1;
    while (tmp[0] != '\n' && cc != 0 && j < 20)
        {
            if (i >= stop && stop > 0)
                {
                    cc = read(fd, tmp, 1);  
                }
            else
            {
                cc = read(fd, tmp, 1);  
                
            }
            if (tmp[0] != '\n')
            {
                buf[j] = tmp[0];
            }
            i++;
            j++;
        }
    if (cc == 0)
        return (0);
    stop = i;
    free(tmp);
    ret = get_buf(&buf);
    free(buf);
    return (ret);
}