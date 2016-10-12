/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 14:23:51 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/08 22:06:41 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		fill_planes_data(t_scene *s, char *data, int counts[4])
{
	int		i;
	int		j;
	char	*request;

	i = 0;
	j = counts[0] + counts[1] + counts[2];
	while (i < counts[3])
	{
		request = construct_request_int("planes.#.pos.x", i);
		s->objs[i + j].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("planes.#.pos.y", i);
		s->objs[i + j].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("planes.#.pos.z", i);
		s->objs[i + j].pos.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("planes.#.normal.x", i);
		s->objs[i + j].rot.x = read_double_data(data, request);
		free(request);
		request = construct_request_int("planes.#.normal.y", i);
		s->objs[i + j].rot.y = read_double_data(data, request);
		free(request);
		request = construct_request_int("planes.#.normal.z", i);
		s->objs[i + j].rot.z = read_double_data(data, request);
		free(request);
		request = construct_request_int("planes.#.color", i);
		s->objs[i + j].color = read_color_data(data, request);
		free(request);
		s->objs[i + j].type = PLANE;
		++i;
	}
}
