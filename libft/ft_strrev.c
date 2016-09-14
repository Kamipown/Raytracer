/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 20:45:33 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/16 12:56:07 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	if ((str = (char *)malloc(len + 1)))
	{
		while (i < len)
		{
			str[i] = s[len - i - 1];
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
