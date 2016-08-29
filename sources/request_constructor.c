/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_constructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 13:29:03 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/29 13:29:04 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	total_len(char *request, char *number)
{
	int		number_len;
	int		ret;

	ret = 1;
	number_len = ft_strlen(number);
	while (*request)
	{
		if (*request == '#')
			ret += number_len;
		else
			++ret;
		++request;
	}
	return (ret);
}

static int	copy_number(char *ret, char *number, int i)
{
	while (*number)
	{
		ret[i++] = *number;
		++number;
	}
	return (i);
}

char		*construct_request_int(char *request, int n)
{
	char	*ret;
	char	*number;
	int		i;

	ret = 0;
	number = ft_itoa(n);
	if ((ret = (char *)malloc(total_len(request, number))))
	{
		i = 0;
		while (*request)
		{
			if (*request == '#')
				i = copy_number(ret, number, i);
			else
				ret[i++] = *request;
			++request;
		}
		ret[i] = '\0';
	}
	free(number);
	return (ret);
}
