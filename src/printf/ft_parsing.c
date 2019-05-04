/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:07:15 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:07:17 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_parse_int(char **format)
{
    int ret;

    ret = 0;
    while (**format)
    {
        if (!ft_isdigit(**format))
            break ;
        ret = ret * 10 + *(*format)++ - '0'; //atoi
    }
    return (ret);
}

int		ft_parse_modifier(char **format)
{
	int ret;

	ret = none;
	if (**format == 'l')
	{
		ret = l;
		if (*(*format)++ && **format == 'l')
			ret = ll;
	}
	if (**format == 'h')
	{
		ret = h;
		if (*(*format)++ && **format == 'h')
			ret = hh;
	}
	if (**format == 'j')
		ret = j;
	if (**format == 'z')
		ret = z;
	if (*format && ret != none && ret != l && ret != h)
		(*format)++;
	return (ret);
}

char    *ft_parse_args(t_data *data, char **format)
{
    ft_init_flags(data);
    data->width = -1; //width de 0 possible
    ft_get_flags(format, data);
    if (ft_isdigit(**format))
        data->width = ft_parse_int(format);
    if (**format == '.')
    {
        (*format)++;
        data->precision = ft_parse_int(format);
    }
    data->modifier = ft_parse_modifier(format);
    while (ft_isspace(**format))
		(*format)++;
	data->format = **format;
	if (**format)
		(*format)++;
	return (*format);
}

int     check_arg(char **format, va_list ap)
{
    t_data data;

    if (**format == '%')
    {
        (*format)++;
        if (**format)
        {
            *format = ft_parse_args(&data, format);
            return (ft_print_args(&data, ap));
        }
    }
    return (0);
}