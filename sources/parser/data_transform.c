/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 06:40:29 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/08 22:49:48 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		data_to_hex(char *s)
{
	int		ret;
	char	quartet;

	ret = 0;
	if (*s == '#')
	{
		++s;
		while (*s)
		{
			quartet = *s++;
			if (quartet >= '0' && quartet <= '9')
				quartet = quartet - '0';
			else if (quartet >= 'a' && quartet <= 'f')
				quartet = quartet - 'a' + 10;
			else if (quartet >= 'A' && quartet <= 'F')
				quartet = quartet - 'A' + 10;
			else
				quartet = '0';
			ret = (ret << 4) | (quartet & 0x0f);
		}
	}
	if (ret < 0)
		return (0);
	return (ret > 0xffffff ? 0xffffff : ret);
}

int				read_color_data(char *data, char *request)
{
	char	*str_value;
	int		int_value;

	str_value = read_data(data, request);
	int_value = str_value ? data_to_hex(str_value) : 0xffffff;
	free(str_value);
	return (int_value);
}

double			read_double_data(char *data, char *request)
{
	char	*str_value;
	double	double_value;

	str_value = read_data(data, request);
	double_value = (str_value ? ft_atod(str_value) : 0);
	free(str_value);
	return (double_value);
}

int				read_int_data(char *data, char *request)
{
	char	*str_value;
	int		int_value;

	str_value = read_data(data, request);
	int_value = (str_value ? ft_atoi(str_value) : 0);
	free(str_value);
	return (int_value);
}
