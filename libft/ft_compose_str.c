/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compose_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 16:56:02 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/13 18:36:35 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_compose_str(const char *s, const char *chars)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = 0;
	while (s[i])
	{
		while (chars[j] && n == 0)
		{
			if (s[i] == chars[j])
				++n;
			++j;
		}
		if (n == 0)
			return (0);
		else
			n = 0;
		j = 0;
		++i;
	}
	return (1);
}
