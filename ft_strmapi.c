#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*fresh;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		fresh[i] = f(i, s[i]);
		i += 1;
	}
	fresh[i] = '\0';
	return (fresh);
}
