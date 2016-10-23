/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:42:39 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 10:11:17 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		++i;
	if (size > 0)
		while (i < (size - 1) && src[j])
			dst[i++] = src[j++];
	if (j > 0)
	{
		dst[i] = '\0';
		return (ft_strlen(src) + i - j);
	}
	return (ft_strlen(src) + i);
}
