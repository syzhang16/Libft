/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:06:29 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:06:30 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_data *data)
{
	data->space = 0;
	data->hashtag = 0;
	data->plus = 0;
	data->precision = -1; //car un precision de 0 est possible
	data->sign = 0;
}