/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_cap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:05:30 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:05:32 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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