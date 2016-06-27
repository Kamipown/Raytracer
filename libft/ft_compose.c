/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 16:55:51 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/13 18:23:42 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_compose(const char c, const char *chars)
{
	size_t	i;

	i = 0;
	while (chars[i])
	{
		if (c == chars[i])
			return (1);
		++i;
	}
	return (0);
}
