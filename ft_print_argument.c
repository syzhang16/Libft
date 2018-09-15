#include "ft_printf.h"

int		ft_printstr(char *str, t_data *data)
{
	int len;

	len = 0;
	str = (data->precision == -1) ? str : ft_precision(str, data);
	if (data->zero && !data->minus)//si j'ai un 0 et pas de -
	{
		len += ft_prefix(str, data); //je pose le prefix
		len += ft_width(ft_strlen(str), data, str); //puis le champs
		len += write(1, str, ft_strlen(str)); //et enfin le reste
	}
	else if (data->minus) //si j'ai un - (decalage a gauche)
	{
		len += ft_prefix(str, data); //je pose le prefix
		len += write(1, str, ft_strlen(str)); //j'ecris 
		len += ft_width(ft_strlen(str), data, str); //et le champs
	}
	else
	{
		len += ft_width(ft_strlen(str), data, str); //champs
		len += ft_prefix(str, data); //le prefix
		len += write(1, str, ft_strlen(str)); //et le reste
	}
	free(str);
	return (len);
}

int		ft_print_args(t_data *data, va_list ap)
{
	if (data->format == 's' || data->format == 'S')
		return (ft_string(data, ap));
	else if (data->format == 'c' || data->format == 'C')
		return (ft_char(data, ap));
	else if (data->format == 'd' || data->format == 'i')
		return (ft_signed_int(data, ap));
	else if (data->format == 'o' || data->format == 'u' || data->format == 'x'
			|| data->format == 'X')
		return (ft_unsigned_int(data, ap));
	else if (data->format == 'D' || data->format == 'O' || data->format == 'U')
		return (ft_long(data, ap));
	else if (data->format == 'p')
		return (ft_ptr(data, ap));
	ft_init_flags(data);
	return (ft_printstr(ft_ctos(data->format), data));
}