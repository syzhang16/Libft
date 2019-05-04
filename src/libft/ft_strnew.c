/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:25:29 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/01 17:25:29 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strnew;

	if (!(strnew = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(strnew, size + 1);
	return (strnew);
}
