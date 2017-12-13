#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i += 1;
	if (c == s[i] || !c)
		return ((char*)s + i);
	return (NULL);
}
