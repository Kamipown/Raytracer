/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:35:23 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 09:33:08 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*temp1;
	unsigned char		*temp2;

	i = 0;
	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (i < n)
	{
		temp1[i] = temp2[i];
		if (temp1[i] == (unsigned char)c)
			return ((void *)&temp1[i + 1]);
		++i;
	}
	return (NULL);
}
