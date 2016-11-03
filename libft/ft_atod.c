/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 22:45:45 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/08 22:45:52 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_atod_copy(char *s)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != '.')
			str[i++] = *s;
		++s;
	}
	str[i] = '\0';
	return (str);
}

static unsigned int	ft_atod_decimals(char *s)
{
	unsigned int n;

	n = 1;
	while (*s && *s != '.')
		++s;
	if (*s == '.')
		++s;
	while (*s)
	{
		n *= 10;
		++s;
	}
	return (n);
}

double				ft_atod(char *s)
{
	char			*str;
	unsigned int	divider;
	double			ret;

	if (!(str = ft_atod_copy(s)))
		return (0);
	divider = ft_atod_decimals(s);
	ret = (double)ft_atoi(str) / (double)divider;
	free(str);
	return (ret);
}
