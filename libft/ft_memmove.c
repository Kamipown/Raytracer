/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:37:34 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 11:44:15 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tdst;

	if ((tdst = (void *)malloc(len)))
	{
		ft_memcpy(tdst, src, len);
		ft_memcpy(dst, tdst, len);
		free(tdst);
	}
	else
		return (NULL);
	return (dst);
}
