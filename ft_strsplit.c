#include "libft.h"

static int		count(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i += 1;
		if (s[i] != c && s[i] != '\0')
			words += 1;
		while (s[i] != c && s[i] != '\0')
			i += 1;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	size_t	len;

	if (!s)
		return (NULL);
	j = count(s, c);
	if (!(tab = malloc(sizeof(tab) * j + 1)))
		return (NULL);
	tab[j] = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len += 1;
			s++;
		}
		if (len > 0)
			*tab++ = ft_strsub((s - len), 0, len);
	}
	return (tab - j);
}
