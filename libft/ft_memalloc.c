/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 16:05:11 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/09 16:08:51 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	if (size == 0)
		return (0);
	memory = NULL;
	if ((memory = (void *)malloc(sizeof(*memory) * size)) == NULL)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
