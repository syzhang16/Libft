#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = (char*)(malloc(sizeof(char) * ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
