/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_iul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:06:12 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:06:15 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		ft_signed_int(t_data *data, va_list ap)
{
	intmax_t i;

	if (data->modifier == h)
		i = (short)va_arg(ap, int);
	else if (data->modifier == hh)
		i = (signed char)va_arg(ap, long long);
	else if (data->modifier == l)
		i = (long)va_arg(ap, long long);
	else if (data->modifier == ll)
		i = (long long)va_arg(ap, long long);
	else if (data->modifier == j)
		i = (intmax_t)va_arg(ap, long long);
	else if (data->modifier == z)
		i = (size_t)va_arg(ap, long long);
	else
		i = (int)va_arg(ap, long long int);
	if (i < 0)
	{
		data->sign = 1;
		i *= -1;
	}
	return (ft_printstr(ft_itoa_b(i, 10), data));
}

uintmax_t		ft_unsigned_int(t_data *data, va_list ap)
{
	uintmax_t i;

	if (data->modifier == hh)
		i = (unsigned char)va_arg(ap, unsigned long long int);
	else if (data->modifier == h)
		i = (unsigned short int)va_arg(ap, unsigned long long int);
	else if (data->modifier == l)
		i = (unsigned long)va_arg(ap, unsigned long long int);
	else if (data->modifier == ll)
		i = va_arg(ap, unsigned long long int);
	else if (data->modifier == j)
		i = (uintmax_t)va_arg(ap, unsigned long long int);
	else if (data->modifier == z)
		i = (size_t)va_arg(ap, unsigned long long int);
	else
		i = (unsigned int)va_arg(ap, unsigned long long int);
	data->space = 0;
	data->plus = 0;
	if (data->format == 'x')
		return (ft_printstr(ft_strtolower(ft_itoa_b(i, 16)), data));
	if (data->format == 'X')
		return (ft_printstr(ft_itoa_b(i, 16), data));
	if (data->format == 'o')
		return (ft_printstr(ft_itoa_b(i, 8), data));
	return (ft_printstr(ft_itoa_b(i, 10), data));
}

int		ft_long(t_data *data, va_list ap)
{
	long long int		i;
	unsigned long long	ui;

	ui = 0;
	if (data->format == 'D')
	{
		i = va_arg(ap, long int);
		if (i < 0)
		{
			data->sign = 1;
			i *= -1;
		}
		return (ft_printstr(ft_itoa_b(i, 10), data));
	}
	i = 0;
	ui = (unsigned long int)va_arg(ap, long int);
	data->space = 0;
	data->plus = 0;
	if (data->format == 'O')
		return (ft_printstr(ft_itoa_b(ui, 8), data));
	return (ft_printstr(ft_itoa_b(ui, 10), data));
}