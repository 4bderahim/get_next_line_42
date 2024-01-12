#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{

    // int t = open("hello", O_RDONLY);
    // int d = 0;

    char *buf;
    buf = (char *) malloc(10);
    buf[10] = 0;
    printf("%lu\n", sizeof(buf));
    buf = (char *) realloc(buf, 20);
    buf[20] = 0;
    printf("%lu", sizeof(char) * 20);
    free(buf);
    printf("__[%lu", BUFFER_SIZE);
    //close(t);
    //printf("[%d}[%s]",i ,buf);
}