#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s);
	tmp = NULL;
	while (s[i] != c && i >= 0)
		i -= 1;
	if (c == s[i] || !c)
		return (tmp = (char*)s + i);
	return (tmp);
}
