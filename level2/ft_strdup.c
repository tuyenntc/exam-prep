/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int i = 0;
	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (*src)
		dup[i++] = *src++;
	dup[i] = '\0';
	return (dup);
}

int	main(int ac, char **av)
{
	char	*mine;
	char	*lib;
	if (ac == 2)
	{
		mine = ft_strdup(av[1]);
		lib = strdup(av[1]);
		printf(":%s:\n:%s:\n", mine, lib);
	}
	return (0);
}

/*
char	*ft_strdup(char *src)
{
	char	*dup;
	int		len = 0;
	int		i = 0;
	while (src[len])
		len++;
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
*/
/*

#include <stdio.h>

int	main(void)
{
	char	*origin = "hello";
	char	*dup;
	dup = ft_strdup(origin);
	if (dup)
	{
		printf("origin str: %s\n", origin);
		printf("duplicate str: %s\n", dup);
	}
	else
		printf("memory allocation fails\n");
	free(dup);
	return (0);
}
*/
