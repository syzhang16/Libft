#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*u1;
	unsigned char	*u2;

	if (!s1 && !s2)
		return (0);

	i = 0;
	u1 = (unsigned char*)s1;
	u2 = (unsigned char*)s2;
	while (i < n)
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		i += 1;
	}
	return (0);
}
