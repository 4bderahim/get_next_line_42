#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
int funchioning_function(int x)
{
    static int count;

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