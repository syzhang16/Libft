/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:07:35 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:07:36 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prefix(char *str, t_data *data)
{
	int len;

	len = 0;
	if ((data->format == 'o' || data->format == 'O') && data->hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0))
		len += write(1, "0", 1);
	if (data->format == 'p' || (data->format == 'x' && data->hashtag &&
				((*str && str[0] != '0') || data->precision > 0)))
		len += write(1, "0x", 2);
	if (data->format == 'X' && data->hashtag &&
			((*str && str[0] != '0') || data->precision > 0))
		len += write(1, "0X", 2);
	if (data->sign)
		len += write(1, "-", 1);
	if (!data->sign && data->plus)
		len += write(1, "+", 1);
	if (!data->sign && !data->plus && data->space &&
			data->format != '%')
		len += write(1, " ", 1);
	return (len);
}