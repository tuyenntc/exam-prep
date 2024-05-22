/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>


int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i])
			i++;
		while (i--)
			write(1, &av[1][i], 1);
//		while (i)
//			write(1, &av[1][--i], 1);
	}
	write(1, "\n", 1);
	return (0);
}

/*
// 2nd solution:

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int len;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		while (len--)
			write(1, &av[1][len], 1);
	}
	write(1, "\n", 1);
	return (0);
}
*/

/*
// 3rd: calculate length in the loop:
int main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];
		char	*end = s;

		while (*end)
			end++;//move end to the end of the string
		while (end != s)
			write(1, --end, 1);
	}
	write(1, "\n", 1);
	return (0);
}
*/

// 4th: pointer arithmetic: 
/* only access av[1] if there are 2 arguments; 
* otherwise -->segmentation fault; 
* that is why I moved the len after the condition check ac == 2
*
*/
/*
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*str = av[1];
		int		len = ft_strlen(str);
		while (len--)
			write(1, &str[len], 1);
	}
	write(1, "\n", 1);
	return (0);
}

*/
/*
// 5th: using recursion
void	print_reverse(char *s, int len)
{
	if (len > 0)
	{
		write(1, &s[len - 1], 1);
		print_reverse(s, len - 1);
	}
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int len = ft_strlen(av[1]);
		print_reverse(av[1], len);
	}
	write(1, "\n", 1);
	return (0);
}

*/
