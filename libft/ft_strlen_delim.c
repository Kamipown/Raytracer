/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_delim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 02:03:51 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/16 02:05:37 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_delim(const char *s, const char delim)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delim)
		++i;
	return (i);
}
