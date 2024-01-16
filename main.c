#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{

    int t = open("hello", O_RDONLY);
    //int d = 0;
   printf("=%s=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   printf("=[%s]=\n", get_next_line(t));
   //system("leaks -q a.out");
    close(t);
    //printf("[%d}[%s]",i ,buf);
}