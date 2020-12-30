#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

void	*ft_memalloc(size_t size)
{
	void	*r;

	if (!(r = malloc(size)))
		return (NULL);
	bzero(r, size);
	return (r);
}




void    func(char **s)
{
    printf("inside1\t=[%p]\n", *s);
    *s = ft_memalloc(9000);
    printf("inside2\t=[%p]\n", *s);
}

int     main()
{
    char *s1;

    s1 = (char *)ft_memalloc(sizeof(char) * 10);
    printf("before\t=[%p]\n", s1);
    func(&s1);
    printf("after\t=[%p]\n", s1);

}