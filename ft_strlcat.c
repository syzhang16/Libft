#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	k = ft_strlen(src);
	j = 0;
	if (!dstsize)
		return (k);
	while (src[j] != '\0' && ((i + j) < (dstsize - 1)))
	{
		dst[i + j] = src[j];
		j += 1;
	}
	dst[i + j] = '\0';
	if (i < dstsize)
		return (i + k);
	return (k + dstsize);
}
