#include "ft_printf.h"

void	ft_get_flags(char **format, t_data *data)
{
	data->minus = 0;
	data->zero = 0;
	while (**format && (**format == '#' || **format == ' ' || **format == '0'
			|| **format == '+' || **format == '-'))
	{
		if (**format == '#')
			data->hashtag = 1;
		if (**format == ' ')
			data->space = 1;
		if (**format == '0')
			data->zero = 1;
		if (**format == '+')
			data->plus = 1;
		if (**format == '-')
			data->minus = 1;
		(*format)++;
	}
}