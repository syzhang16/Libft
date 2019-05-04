/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:08:21 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:08:21 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wclen(wchar_t c)
{
    if (c >= 0)
    {
        if ((c <= 0x7F && MB_CUR_MAX > 0) || (c <= 0xFF && MB_CUR_MAX == 1))
            return (1);
        else if (c <= 0x7FF && MB_CUR_MAX > 1)
            return (2);
        else if (c <= 0xFFFF && MB_CUR_MAX > 2)
            return (3);
        else if (c <= 0x10FFFF && MB_CUR_MAX > 3)
            return (4);
    }
    return (0);
}

int		ft_wcslen(wchar_t *s)
{
	int size;

	size = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (!(ft_wclen(*s)))
			return (-1);
		size += ft_wclen(*s);
		s++;
	}
	return (size);
}

char	*ft_wctostr(wchar_t c)
{
	char *str;

	if (!(str = ft_strnew(ft_wclen(c))))
		return (NULL);
	if ((c <= 0x7F && MB_CUR_MAX >= 1) || (c <= 0xFF && MB_CUR_MAX == 1))
		str[0] = (unsigned char)c;
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		str[0] = (c >> 12) | 0xE0;
		str[1] = (c >> 6 & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
	{
		str[0] = (c >> 18) | 0xF0;
		str[1] = (c >> 12 & 0x3F) | 0x80;
		str[2] = (c >> 6 & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
	}
	return (str);
}