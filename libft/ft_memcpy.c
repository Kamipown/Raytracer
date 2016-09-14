/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:37:11 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 09:31:57 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*temp1;
	const char	*temp2;

	i = 0;
	temp1 = (char *)dst;
	temp2 = (char *)src;
	while (i < n)
	{
		temp1[i] = temp2[i];
		++i;
	}
	return (dst);
}
