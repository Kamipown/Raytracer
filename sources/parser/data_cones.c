/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cones.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:18:06 by dcognata          #+#    #+#             */
/*   Updated: 2016/09/17 14:11:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		fill_cones_data(t_scene *s, char *data, int counts[4])
{
	int		i;
	int		j;
	char	*request;

	i = 0;
	j = counts[0] + counts[1];
	while (i < counts[2])
	{
		request = construct_request_int("cones.#.pos.x", i);
		s->objs[i + j].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.pos.y", i);
		s->objs[i + j].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.pos.z", i);
		s->objs[i + j].pos.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.normal.x", i);
		s->objs[i + j].rot.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.normal.y", i);
		s->objs[i + j].rot.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.normal.z", i);
		s->objs[i + j].rot.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.radius", i);
		s->objs[i + j].radius = read_int_data(data, request);
		free(request);
		request = construct_request_int("cones.#.color.r", i);
		s->objs[i + j].color.r = read_color_data(data, request);
		free(request);
		request = construct_request_int("cones.#.color.g", i);
		s->objs[i + j].color.g = read_color_data(data, request);
		free(request);
		request = construct_request_int("cones.#.color.b", i);
		s->objs[i + j].color.b = read_color_data(data, request);
		free(request);
		request = construct_request_int("cones.#.reflection", i);
		s->objs[i + j].refl = read_color_data(data, request);
		free(request);
		s->objs[i + j].type = CONE;
		++i;
	}
}
