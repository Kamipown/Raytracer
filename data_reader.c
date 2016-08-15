/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 21:01:05 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/06 21:01:06 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	count_tabs(char *request)
{
	int		ret;

	ret = 0;
	while (*request)
	{
		if (*request == '.')
			++ret;
		++request;
	}
	return (ret);
}

static char	*browse(char *data, char *request, int tab)
{
	int		i;

	i = 0;
	while (i <= tab)
	{
		while (*request && *request != '.')
		{
			++request;
		}
		++request;
		++i;
	}
	ft_putendl(request);
	ft_putchar('\n');
	return (data);
}

int			read_data(char *data, char *request)
{
	int		tab_count;
	int		tab;

	tab_count = count_tabs(request);
	tab = 0;
	while (tab < tab_count)
	{
		data = browse(data, request, tab);
		++tab;
	}
	return (tab_count);
}
