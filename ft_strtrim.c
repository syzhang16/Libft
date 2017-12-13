#include <stdlib.h>
#include "libft.h"

static int		ft_start(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i += 1;
	return (i);
}

static int		ft_end(char const *s)
{
	int	j;

	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j -= 1;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*fresh;
	int		len;

	if (!s)
		return (NULL);
	len = ft_end(s) - ft_start(s);
	len = (len < 0) ? -len : len;
	fresh = NULL;
	fresh = ft_strsub(s, ft_start(s), len + 1);
	return (fresh);
}
