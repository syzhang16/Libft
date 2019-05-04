/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:05:52 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:05:53 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(t_data *data, va_list ap)
{
	char	c;
	int		len;

	len = 0;
	if (data->format == 'C' || (data->format == 'c' && data->modifier == l))
		return (ft_c_cap(data, ap));
	c = va_arg(ap, int);
	if (data->minus)
	{
		len += write(1, &c, 1);
		len += ft_width(1, data, ft_ctos(c));
	}
	else
	{
		len += ft_width(1, data, ft_ctos(c));
		len += write(1, &c, 1);
	}
	return (len);
}

//on envoie un void* et on recupere de le forme que l'on veut ici je recupere en size_t
int		ft_ptr(t_data *data, va_list ap)
{
	size_t		value;

	value = va_arg(ap, size_t);
	data->hashtag = 1; //car le # est par defaut avec le %p donc = 1
	data->space = 0;   //pas par defaut donc = 0
	data->plus = 0;	   //pareil que ' '
	return (ft_printstr(ft_strtolower(ft_itoa_b(value, 16)), data));
}

int		ft_string(t_data *data, va_list ap)
{
	char	*str;

	if (data->format == 'S' || (data->format == 's' && data->modifier == l))
		return (ft_s_cap(data, ap));
	str = va_arg(ap, char *);
	data->space = 0;
	data->plus = 0;
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (data->format == 's')
		return (ft_printstr(str, data));
	return (0);
}