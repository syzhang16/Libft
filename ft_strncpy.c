#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i += 1;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i += 1;
	}
	return (dst);
}
