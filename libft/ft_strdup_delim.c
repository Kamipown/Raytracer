/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_delim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 01:53:35 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/16 02:01:23 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_delim(const char *s1, const char delim)
{
	char	*str;
	size_t	i;

	if ((str = (char *)malloc(ft_strlen_delim(s1, delim) + 1)))
	{
		i = 0;
		while (s1[i] && s1[i] != delim)
		{
			str[i] = s1[i];
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
