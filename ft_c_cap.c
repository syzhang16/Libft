#include "ft_printf.h"

int		ft_c_cap(t_data *data, va_list ap)
{
	wint_t	c;
	int		len;
	char	*str;

	c = va_arg(ap, wchar_t);
	if (!(ft_wclen(c)))
		return (-1);
	len = 0;
	if (!(str = ft_wctostr(c)))
		return (-1);
	if (data->minus)
	{
		len += write(1, str, ft_wclen(c));
		len += ft_width(ft_wclen(c), data, str);
	}
	else
	{
		len += ft_width(ft_wclen(c), data, str);
		len += write(1, str, ft_wclen(c));
	}
	return (len);
}