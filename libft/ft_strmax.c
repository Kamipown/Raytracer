/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 12:07:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/16 12:24:52 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmax(const char *s, const size_t c)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (len > c)
		len = c;
	if ((ret = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
