/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:06:21 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:06:22 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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