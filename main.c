#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
void f(int a, int b, int c , int r, int w, int aa, int p, int i, int cc)
{
	int *tt = &w;
	int ii =0;
	while (ii < 8)
	{
		printf("\t{%d::%d}\n\n", *(&aa), *(&aa-8));
		printf("%lu::%lu::	[%d]\n",(unsigned long)&i, (unsigned long)&cc-ii, *(int *)(&cc-(ii)));
		ii += 2;
	}
}
int main()
{
	ft_printf("%d %d %d %d %d %d %d %d", 222, 456, 6666, 7777, 888, 50, 49, 99);    
	f(49,29,11,1,2,3,4,12593,111111);
}

//[----][----][----][----][----]
