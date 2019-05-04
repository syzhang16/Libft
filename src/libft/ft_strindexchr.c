/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:34:47 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:35:02 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strindexchr(char const *s, char c)
{
	int	i;

	i = -1;
	if (!s)
		return (-2);
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}