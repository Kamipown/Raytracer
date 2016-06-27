/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:44:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/09 16:29:32 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((start + len) > ft_strlen(s))
		return (NULL);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))))
	{
		while (i < len)
		{
			str[i] = s[start + i];
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
