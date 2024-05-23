/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

#include <stdio.h>
int	main(void)
{
	char	*s1 = "hallo";
	char	*s2 = "hallo";
	int	res = ft_strcmp(s1, s2);
	if (res > 0)
		printf("s1 > s2\n");
	else if (res < 0)
		printf("s1 < s2\n");
	else
		printf("s1 = s2\n");
	return (0);
}
