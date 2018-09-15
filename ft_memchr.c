#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char)c) == ((unsigned char*)s)[i])
			return ((void*)(s + i));
		i += 1;
	}
	return (NULL);
}
