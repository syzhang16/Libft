#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	j;

	j = 0;
	fresh = NULL;
	if (s == NULL)
		return (NULL);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	if (len > 0)
	{
		while (j < len)
		{
			fresh[j] = s[start + j];
			j += 1;
		}
	}
	fresh[j] = '\0';
	return (fresh);
}
