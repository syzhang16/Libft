#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				j += 1;
				if (needle[j] == '\0')
					return ((char*)haystack + i);
			}
			j = 0;
		}
		i += 1;
	}
	return (NULL);
}
