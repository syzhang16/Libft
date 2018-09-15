#include "ft_printf.h"

void	ft_strset(char *str, char c, size_t start, size_t end)
{
	while (start < end)
	{
		str[start] = c;
		start++;
	}
}