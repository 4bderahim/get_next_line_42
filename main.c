#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int func(int x)
{
    static int count;

    count += x;
    return count;
}
char *get_next_line(int fd)
{
    char *buf;
    static int stop;
    buf = (char *) malloc(12);
    if (!buf)
        return (0);
    buf[12] = '\0';
    int i = 0;
    ssize_t cc;
    while (buf[0] != '\n')// || buf[0] != '\n')
        {
                cc = read(fd, buf, 1);
            i++; 
            //printf("--->>>>>>{{{%c]\n", buf[0]);
        }
    
    printf("==[%d]===\n",i);
    
    
    
    //if (buf[0] != '\0')
    cc = read(fd, buf,12);
    printf("\t\t\t\t\t [[[%s]]<\n", buf);
    return (buf);
}
int main()
{
    int t = open("text.txt", O_RDONLY);
    int d = 0;
    printf("__%s", get_next_line(t));
    //printf("__%s", get_next_line(t));
      
    //printf("[%d}[%s]",i ,buf);
}