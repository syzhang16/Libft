/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:08:14 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:08:15 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strset(char *str, char c, size_t start, size_t end)
{
	while (start < end)
	{
		str[start] = c;
		start++;
	}
}