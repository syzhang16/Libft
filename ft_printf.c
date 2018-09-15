#include "ft_printf.h"

int		ft_print_start(const char *format, va_list ap)
{
	int		len;
	int		tmp;
	char	*fmt;

	len = 0;
	fmt = (char *)format;
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			len += write(1, fmt++, 1);
		}
		if (*fmt == '%')
		{
			if ((tmp = check_arg(&fmt, ap)) == -1)
				return (-1);
			len += tmp;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (format)
	{
		va_start(ap, format);
		len = ft_print_start(format, ap);
		va_end(ap);
	}
	return (len);
}