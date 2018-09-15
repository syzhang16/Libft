#include "ft_printf.h"

char	*ft_strtolower(char *str)
{
	char *s;

	s = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (s);
}