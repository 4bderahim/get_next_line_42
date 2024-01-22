#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{

    int t = open("he", O_RDONLY);
    //int d = 0;
    char *s1 = get_next_line(t);
    char *s2 = get_next_line(t);
     char *s3 = get_next_line(t);
      char *s4 = get_next_line(t);
      char *s5 = get_next_line(t);
    printf("%s", s1);
    printf("%s", s2);
    printf("%s", s3);
    printf("%s", s4);
    printf("%s", s5);
   
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
//    printf("=%s=\n", get_next_line(t));
   //system("leaks -q a.out");
    close(t);
    //printf("[%d}[%s]",i ,buf);
}
