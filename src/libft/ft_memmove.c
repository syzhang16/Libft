/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:22:18 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:22:18 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i += 1;
		}
	else
		while (len > 0)
		{
			((char*)dst)[len - 1] = ((char*)src)[len - 1];
			len -= 1;
		}
	return (dst);
}
