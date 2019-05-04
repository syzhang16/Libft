/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:25:59 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:25:59 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	j;

	j = 0;
	fresh = NULL;
	if (s == NULL)
		return (NULL);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	if (len > 0)
	{
		while (j < len)
		{
			fresh[j] = s[start + j];
			j += 1;
		}
	}
	fresh[j] = '\0';
	return (fresh);
}
