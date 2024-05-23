/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

#include <unistd.h>
/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*str = av[1];
		char	c;
		int		i = 0;
		while (str[i])
		{
			c = str[i];
			if (c >= 'a' && c <= 'z')
				c = 'z' - (c - 'a');
			else if (c >= 'A' && c <= 'Z')
				c = 'Z' - (c - 'A');
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/

/*
// 2nd solution:  using pointer
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];
		while (*s)
		{
			char	c = *s;
			if (c >= 'a' && c <= 'z')
				c = 'z' - (c - 'a');
			else if (c >= 'A' && c <= 'Z')
				c = 'Z' - (c - 'A');
			write(1, &c, 1);
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/

void	print_mirror(char c)
{
	if (c >= 'a' && c <= 'z')
		c = 'z' - (c - 'a');
	else if (c >= 'A' && c <= 'Z')
		c = 'Z' - (c - 'A');
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			print_mirror(av[1][i++]);
	}
	write(1, "\n", 1);
	return (0);
}


/*
// 4th solution:  using a helper function:

char	mirror_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('z' - (c - 'a'));
	else if (c >= 'A' && c <= 'Z')
		return ('Z' - (c - 'A'));
	else
		return (c);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];
		int		i = 0;
		while (s[i])
		{
			char	mirrored = mirror_char(s[i]);
			write(1, &mirrored, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/

int	main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 65 && av[1][i] <= 90)
				av[1][i] = 90 - av[1][i] + 65;
			else if (av[1][i] >= 97 && av[1][i] <= 122)
				av[1][i] = 122 - av[1][i] + 97;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
