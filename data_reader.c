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

// static int	count_tabs(char *request)
// {
// 	int		ret;

// 	ret = 0;
// 	while (*request)
// 	{
// 		if (*request == '.')
// 			++ret;
// 		++request;
// 	}
// 	return (ret);
// }

// static char	*get_line()
// {
	
// }

// static char	*proceed_data(char *data, char *request, int tab_count)
// {
// 	int		i;

// 	i = 0;
// 	while (*data)
// 	{

// 		++data;
// 	}
// }

// static int	browse(char *data, char *request, int tab_count)
// {
// 	int		i;

// 	i = 0;
// 	while (i < tab_count)
// 	{
// 		data = proceed_data(data, request, i);
// 		request = proceed_request();
// 		++i;
// 	}
// 	ft_putendl(request);
// 	ft_putchar('\n');
// 	return (data);
// }

int			read_data(char *data, char *request)
{
	// int		tab_count;
	// int		ret;

	// tab_count = count_tabs(request);
	// ret = browse(data, request, tab_count);
	// return (ret);
	if (data && request)
		return (1);
	return (0);
}
