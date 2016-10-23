/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 20:49:32 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/13 11:24:06 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *s, const char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	str = (char *)malloc(i + 1);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
