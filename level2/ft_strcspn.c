/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:
size_t	ft_strcspn(const char *s, const char *reject);
--> find offset of first character match
*/

#include <stddef.h> //for size_t
/*
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i, j;
	i = j = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);//if found no match, this is the '\0'
}
*/
//for loop
size_t	ft_strcspn(const char *s, const char *reject)
{
	for (size_t i = 0; s[i] != '\0'; i++)
	{
		for (size_t j = 0; reject[j] != '\0'; j++)
		{
			if (s[i] == reject[j])
				return (i);
		}
	}
	return (0);
}

// pointer
size_t ft_strcspn(const char *s, const char *reject)
{
	const char	*p;
	const char	*r;
	for (p = s; *p != '\0'; p++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*p == *r)
				return (p - s);
		}
	}
	return (p - s);
}
/*

#include <stdbool.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
	bool	set[256] = {false};
	size_t	i;
	for (size_t i = 0; reject[i] != '\0'; i++)
	{
		set[(unsigned char)reject[i]] = true;
	}
	for (size_t i = 0; s[i] != '\0'; i++)
	{
		if (set[(unsigned char)s[i]])
			return (i);
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	const char 	*s = "hello world";
	const char	*reject = " ";
	size_t result = ft_strcspn(s, reject);
	printf("str is %s - finding text %s - offset is %zu", s, reject, result);
	return (0);
}
*/
