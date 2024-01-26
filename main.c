#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		t,y;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	t = open("he", O_RDONLY);
    y = open("hello", O_RDONLY);
	// int d = 0;
	s1 = get_next_line(t);
	s2 = get_next_line(y);
	s3 = get_next_line(t);
	s4 = get_next_line(y);
    //s4 = get_next_line(455645555);
	// s5 = get_next_line(t);
	printf("%s", s1);
	printf("[%s]", s2);
	printf("%s", s3);
    printf("%s", s4);
	// printf("%s", s5);
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	//    printf("=%s=\n", get_next_line(t));
	system("leaks -q a.out");
	close(t);
	close(y);
	// printf("[%d}[%s]",i ,buf);
}
