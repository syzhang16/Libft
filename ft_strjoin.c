#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(fresh) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[j] != '\0')
	{
		fresh[i] = s1[j];
		i += 1;
		j += 1;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		fresh[i] = s2[j];
		i += 1;
		j += 1;
	}
	fresh[i] = '\0';
	return (fresh);
}
