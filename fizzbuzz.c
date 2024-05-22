/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

/*
void	ft_write_nb(int number)
{
	char	s[10] = "0123456789";
	if (number > 9)
		ft_write_nb(number / 10);
	write(1, &s[number % 10], 1);
}

int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else
			ft_write_nb(i);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
*/
/*
in c, there is no string, so when storing string, we basically store an array of characters terminated by a null terminator -->select an array with the [] to select a specific index; the second argument of the write function is a char * so the & character in front of the string -->give a pointer to the specific character to write
*/
void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}
/*
int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 5 == 0 && i % 3 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}

*/

int main(void)
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
	}
	return (0);
}
