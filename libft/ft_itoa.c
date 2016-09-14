/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:34:50 by pdelobbe          #+#    #+#             */
/*   Updated: 2015/11/09 14:38:55 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_putnbr(char *str, size_t i, int n)
{
	if (n >= 10 || n <= -10)
	{
		if (n > 0)
			str[i] = (n % 10) + '0';
		else
			str[i] = -(n % 10) + '0';
		ft_itoa_putnbr(str, i - 1, n / 10);
	}
	else
	{
		if (n > 0)
			str[i] = n + '0';
		else
			str[i] = -n + '0';
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		tempn;

	tempn = n;
	str = NULL;
	len = 1;
	while (tempn /= 10)
		++len;
	if ((str = (char*)malloc(len + (n < 0 ? 2 : 1))) == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		ft_itoa_putnbr(&str[1], len - 1, n);
	}
	else
		ft_itoa_putnbr(str, len - 1, n);
	if (n < 0)
		str[len + 1] = 0;
	else
		str[len] = 0;
	return (str);
}
