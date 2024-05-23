/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter except for the first one.

A snake_case string is a string where each word is in lower case, separated by an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>


// 1st solution:

int	main(int ac, char **av)
{
	int i;
	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				av[1][i] += 32;
				write(1, "_", 1);
			}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// 2nd solution: use helper function

void	get_char(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		write(1, "_", 1);
	}
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i = 0;
	if (ac == 2)
		while (av[1][i])
			get_char(av[1][i++]);
	write(1, "\n", 1);
	return (0);
}

/*
// 3rd solution:

void	camel_to_snake(char *s)
{
	int 	i = 0;
	char	c;
	while (s[i])
	{
		c = s[i];
		if (c >= 'A' && c <= 'Z')
		{
			c += 32;
			write(1, "_", 1);
		}
		write(1, &c, 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write(1, "\n", 1);
	return (0);
}
*/

// allowed functions including malloc, realloc so just a blind guess, they want us to implement with them

int	ft_strlen(const char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}


/* side note: allocate twice the size of the string + 1 
*  as each uppercase letter is replaced by 1 lowercase letter + "_" 
*  use malloc to allocate memory OR can allocate a big buffer to hold
*  the whole input and write from that buffer: 
*  char buffer[1024]
*/

void	camel_to_snake(const char *s)
{
	int		len;
	char	*buffer;
	int		j;
	j = 0;
	len = ft_strlen(s);
	buffer = (char *)malloc(2 * len + 1);
	if (!buffer)
		return;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			buffer[j++] = '_';
			buffer[j++] = s[i] + 32;
		}
		else
			buffer[j++] = s[i];
	}
	buffer[j] = '\0';
	write(1, buffer, j);
	free(buffer);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write(1, "\n", 1);
	return (0);
}
