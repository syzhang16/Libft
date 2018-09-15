#include "ft_printf.h"

size_t		ft_count_len(unsigned long long n, int base, size_t count)
{
	return (n > 0) ? ft_count_len(n / base, base, count + 1) : count;
}

char		*ft_itoa_b(unsigned long long n, int base)
{
	size_t	digit;
	char	*str;

	digit = (n) ? ft_count_len(n, base, 0) : 1;
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit] = '\0';
	while (digit--)
	{
		str[digit] = ft_abs(n % base) + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
	}
	return (str);
}