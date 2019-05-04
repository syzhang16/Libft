/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_cap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:08:00 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:08:00 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_s_cap_precision(wchar_t *str, t_data *data)
{
	int i;
	int preci;

	i = -1;
	preci = 0;
	while (str[++i])
	{
		if (preci + ft_wclen(str[i]) > data->precision)
			break ;
		else
			preci += ft_wclen(str[i]);
	}
	return (preci);
}

int			ft_s_cap(t_data *data, va_list ap)
{
	wchar_t	*s;
	int		size;
	char	*str;
	char	*tmp;

	size = -1;
	s = va_arg(ap, wchar_t *);
	data->space = 0;
	data->plus = 0;
	if (!s)
		return (ft_printstr(ft_strdup("(null)"), data));
	if (ft_wcslen(s) == -1)
		return (-1);
	if (!(str = ft_strnew(ft_wcslen(s))))
		return (-1);
	while (s[++size])
	{
		tmp = ft_wctostr(s[size]);
		ft_strcat(str, tmp);
		free(tmp);
	}
	if (data->precision != -1)
		data->precision = ft_s_cap_precision(s, data);
	return (ft_printstr(str, data));
}