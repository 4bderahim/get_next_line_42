#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
int funchioning_function(int x)
{
    static int count;

    count += x;
    return count;
}

char *get_next_line(int fd)
{
    char *buf;
    char *tmp;
    static int stop;
    
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
    stop = i;
    free(tmp);
  //  printf("{{%d}}", i);
    //cc = read(fd, buf, i-1);
    //printf("[%s]", buf);;
    return (buf);
}
int main()
{


    int t = open("hello", O_RDONLY);
    int d = 0;



    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));

    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));

    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));

    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
    printf("[%s]\n", get_next_line(t));
   // printf("__[%s", get_next_line(t));
    close(t);
    //printf("[%d}[%s]",i ,buf);
}