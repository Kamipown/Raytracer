/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:31:12 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/06 22:43:55 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		data_get_i_constructed(char *data, char *request, int i)
{
	int		ret;
	char	*tmp_req;

	tmp_req = construct_request_int(request, i);
	ret = read_int_data(data, tmp_req);
	free(tmp_req);
	return (ret);
}

double	data_get_d_constructed(char *data, char *request, int i)
{
	double	ret;
	char	*tmp_req;

	tmp_req = construct_request_int(request, i);
	ret = read_double_data(data, tmp_req);
	free(tmp_req);
	return (ret);
}
