/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:44:29 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 10:19:02 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*str)
		++str;
	if ((char)c == 0)
		return (str);
	while (str >= s)
	{
		if (*str == (char)c)
			return (str);
		--str;
	}
	return (NULL);
}
