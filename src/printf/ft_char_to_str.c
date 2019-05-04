/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:05:41 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:05:43 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctos(int c)
{
	char *str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = c;
	return (str);
}