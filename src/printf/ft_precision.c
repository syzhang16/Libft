/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:07:29 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:07:30 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision(char *str, t_data *data)
{
	int		len;
	char	*s;

	len = ft_max(data->precision, ft_strlen(str)) - ft_strlen(str);
	if (data->format == 'o' && data->hashtag && len > 0)
		len -= 1;
	if (len <= 0 && str[0] == '0')
	{
		free(str);
		s = ft_strnew(0);
		return (s);
	}
	if (data->format == 's' || data->format == 'S')
	{
		s = ft_strsub(str, 0, data->precision);
		return (s);
	}
	s = ft_strnew(data->precision);
	ft_strset(s, '0', 0, len);
	s = ft_strcat(s, str);
	free(str);
	return (s);
}