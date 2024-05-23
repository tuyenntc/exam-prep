/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int) and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

int	ft_atoi(const char *str)
{
	int res = 0;
	int sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	mine;
	int	lib;
	if (ac == 2)
	{
		mine = ft_atoi(av[1]);
		lib = atoi(av[1]);
		printf("mine function: %d | lib: %d\n", mine, lib);
	}
	return (0);
}
