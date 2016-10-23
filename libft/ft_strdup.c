/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:41:16 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/01/14 09:59:55 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if ((str = (char*)malloc(ft_strlen(s1) + 1)))
	{
		while (s1[i])
		{
			str[i] = s1[i];
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
