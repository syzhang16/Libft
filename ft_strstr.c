#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j])
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
