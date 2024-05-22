/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int	num1 = 42;
	int num2 = 20;
	int *ptr1 = &num1;
	int *ptr2 = &num2;
	printf("before swap: num1 is %d | num2 is %d\n", num1, num2);
	ft_swap(ptr1, ptr2);
	printf("after swap: num1 is %d | num2 is %d\n", num1, num2);
	return (0);

}
