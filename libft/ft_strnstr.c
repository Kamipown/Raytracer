/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:25:00 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 11:19:25 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i1;
	size_t	i2;
	size_t	len;

	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	i1 = 0;
	while (s1[i1] && i1 < n)
	{
		i2 = 0;
		while (s2[i2] && (i1 + i2) < n)
		{
			if (s1[i1 + i2] != s2[i2])
				break ;
			i2++;
		}
		if (i2 == len)
			return ((char *)(s1 + i1));
		i1++;
	}
	return (NULL);
}
