#include "ft_printf.h"

char	*ft_ctos(int c)
{
	char *str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = c;
	return (str);
}