/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>
/*

// 1st solution:

char	get_char(char c)
{
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
		c += 13;
	else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		c -= 13;
	return (c);
}

int main(int ac, char **av)
{
	char c;
	char *str;
	if (ac == 2)
	{
		str = av[1];
		while (*str)
		{
			c = get_char(*str);
			write(1, &c, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/

// 2nd solution:
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i])
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'm') ||
				(av[1][i] >= 'A' && av[1][i] <= 'M'))
				av[1][i] += 13;
			else if ((av[1][i] >= 'n' && av[1][i] <= 'z') ||
				(av[1][i] >= 'N' && av[1][i] <= 'Z'))
				av[1][i] -= 13;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
//3rd solution:

void	rot_13(char *s)
{
	int		i = 0;
	char	c;
	while (s[i])
	{
		c = s[i];
		if (c >= 'a' && c <= 'z')
		{
			if (c >= 'a' && c <= 'm')
				c += 13;
			else
				c -= 13;
		}
		if (c >= 'A' && c <= 'Z')
		{
			if (c >= 'A' && c <= 'Z')
				c += 13;
			else
				c -= 13;
		}
		write(1, &c, 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	write(1, "\n", 1);
	return (0);
}

*/
