/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:24:42 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:24:43 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	k = ft_strlen(src);
	j = 0;
	if (!dstsize)
		return (k);
	while (src[j] != '\0' && ((i + j) < (dstsize - 1)))
	{
		dst[i + j] = src[j];
		j += 1;
	}
	dst[i + j] = '\0';
	if (i < dstsize)
		return (i + k);
	return (k + dstsize);
}
