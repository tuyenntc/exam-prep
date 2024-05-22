/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it repeating each alphabetical character as many times as its alphabetical index, followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int	get_letter_count(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	return (1);
}

int main(int ac, char **av)
{
	int	i = 0;
	int	count;
	if (ac == 2)
	{
		while (av[1][i])
		{
			count = get_letter_count(av[1][i]);
			while (count--)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}



/*
using 2 loops: for upper-case letters: -64 to get the alphabetical index
A --> 65 --> 65 - 64 = 1
Z --> 90 --> 90 - 64 = 26

a --> 97 --> 97 - 96 = 1;
z --> 122 --> 122 - 96 = 26
*/
/*
int main(int ac, char **av)
{
	int i;
	int j;
	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 65 && av[1][i] <= 90)
			{
				j = 0;
				while (j < av[1][i] - 64)
				{
					write(1, &av[1][i], 1);
					j++;
				}
			}
			else if (av[1][i] >= 97 && av[1][i] <= 122)
			{
				j = 0;
				while (j <av[1][i] - 96)
				{
					write (1, &av[1][i], 1);
					j++;
				}
			}
			else
				write(1, &av[1][i], 1);//write the character if it is not a letter
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
*/
/*
//solution 2:

void	ft_putchar_n(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		--n;
	}
}

void	repeat_alpha(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			ft_putchar_n(*s, *s + 1 - 'a');
		else if (*s >= 'A' && *s <= 'Z')
			ft_putchar_n(*s, *s + 1 - 'A');
		else
			write(1, s, 1);
		++s;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}

*/
