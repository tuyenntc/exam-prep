/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
s1 = dst
s2 = src;
*/

#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/*
//note: when using pointer: s1 == dst; s2 == src; need to check length for buffer overflow - s1 is not big enough to hold the copied content from s2)

char	*ft_strcpy(char *s1, char *s2)
{
	char	*tmp = s1;
	while (*s2)
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	*tmp = '\0';
	return (s1);
}
*/
int main(void)
{
	char	src[] = "testing";
	char	dst[] = "";
	printf("before copy: src: %s | dst: %s\n", src, dst);
	ft_strcpy(dst, src);
	printf("after copy: src: %s | dst: %s\n",src, dst);
	return (0);
}
