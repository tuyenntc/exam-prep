/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation, followed by a newline. If the number of parameters is not 3, the program just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative numbers, in input or output, will have one and only one leading '-'. The result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	long	nb1;
	long	nb2;
	long	res;

	if (ac == 4)
	{
		nb1 = atoi(av[1]);
		nb2 = atoi(av[3]);
		if (*av[2] == '+')
			res = nb1 + nb2;
		else if (*av[2] == '-')
			res = nb1 - nb2;
		else if (*av[2] == '*')
			res = nb1 * nb2;
		else if (*av[2] == '/')
			res = nb1 / nb2;
		else
			res = nb1 % nb2;
		if (res >= -2147483648 && res <= 2147483647)
			printf("%d",(int)res);
	}
	printf("\n");
	return (0);
}

/*
int	add(int num1, int num2)
{
	return (num1+ num2);
}

int	deduct(int num1, int num2)
{
	return (num1 - num2);
}

int	multiply(int num1, int num2)
{
	return (num1 * num2);
}

int	divide(int num1, int num2)
{
	return (num1 / num2);
}

int	modulo(int num1, int num2)
{
	return (num1 % num2);
}

int main(int ac, char **av)
{
	int		num1, num2, res;
	char	ops;
	if (ac == 4)
	{
			num1 = atoi(av[1]);
			num2 = atoi(av[3]);
			ops = av[2][0];
			switch (ops)
			{
				case '+':
					res = add(num1, num2);
					break;
				case '-':
					res = deduct(num1, num2);
					break;
				case '*':
					res = multiply(num1, num2);
					break;
				case '/':
					if (num2 != 0)
						res = divide(num1, num2);
					else
					{
						printf("error: division by zero\n");
						return (1);
					}
					break;
				case '%':
					if (num2 != 0)
						res = modulo(num1, num2);
					else
					{
						printf("error: modulo by zero\n");
						return (1);
					}
				default:
					printf("\n");
					return (1);
			}
			printf("%d\n", res);
	}
	else
		printf("\n");
	return (0);
}

// 2nd solution:
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		switch(av[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '-':
				printf("%d", atoi(av[1]) - atoi(av[3]));
				break;
			case '*':
				printf("%d", atoi(av[1]) * atoi(av[3]));
				break;
			case '/':
				printf("%d", atoi(av[1]) / atoi(av[3]));
				break;
			case '%':
				printf("%d", atoi(av[1]) % atoi(av[3]));
				break;
		}
	}
	printf("\n");
	return (0);
}
*/
