/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 22:03:36 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/11 20:48:48 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrunc(const char *s, const char c)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] && s[i] != c)
		++i;
	while (s[i] && s[i] == c)
		++i;
	str = (char *)malloc(len - i + 1);
	while (s[i])
	{
		str[j] = s[i];
		++i;
		++j;
	}
	str[j] = '\0';
	return (str);
}
