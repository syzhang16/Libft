/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:08:30 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:08:32 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_widthsize(int len, t_data *data, char *str)
{
	if ((data->format == 'o' || data->format == 'O') && data->hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0))
		len -= 1;
	if (data->format == 'p' || (data->format == 'x' && data->hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0)))
		len -= 2;
	if (data->format == 'X' && data->hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0))
		len -= 2;
	if (data->sign || (!data->sign && data->plus) || (!data->sign &&
				!data->plus && data->space && data->format != '%'))
		len -= 1;
	return (len);
}

int		ft_width(size_t len, t_data *data, char *str)
{
	int		size;
	char	*pad;

	size = ft_max(data->width, len) - len;
	size = ft_widthsize(size, data, str);
	if (size <= 0)
		return (0);
	pad = ft_strnew(size);
	if (data->zero && !data->minus && data->precision <= 0)
	{
		ft_strset(pad, '0', 0, size);
		size = write(1, pad, size);
	}
	else
	{
		ft_strset(pad, ' ', 0, size);
		size = write(1, pad, size);
	}
	free(pad);
	return (size);
}