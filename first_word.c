/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1] && (*av[1] == '\t' || *av[1] == ' '))
			av[1]++;
		while (*av[1] && (*av[1] != '\t' && *av[1] != ' '))
			write(1, av[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
/*
2nd solution:

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while ((av[1][i] != 32 && av[1][i] != 9) && (av[1][i]))
			write(1, &av[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
*/

/*
// 3rd solution: ft_putchar && ft_is space
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_space(int c)
{
	c = (unsigned char)c;
	if (!(c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r')) 
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		while (ft_is_space(av[1][i]))
			i++;
		while (av[1][i] && !ft_is_space(av[1][i]))
		{
			ft_putchar(av[1][i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
*/
/*
// 4th solution:
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_word(const char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	while (*s != ' ' && *s != '\t' && *s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		first_word(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
*/
/*

//5th solution: using function strtok - OR ft_split
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	char	*first_word;
	if (ac == 2)
	{
		first_word = strtok(av[1], " \t");
		if (first_word)
			printf("%s\n", first_word);
		else
			putchar('\n');
	}
	return (0);
}
*/
