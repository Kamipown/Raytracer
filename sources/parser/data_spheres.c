/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:18:06 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/17 14:11:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		fill_spheres_data(t_scene *s, char *data, int counts[4])
{
	int		i;
	char	*request;

	i = 0;
	while (i < counts[0])
	{
		request = construct_request_int("spheres.#.pos.x", i);
		s->objs[i].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.pos.y", i);
		s->objs[i].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.pos.z", i);
		s->objs[i].pos.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.radius", i);
		s->objs[i].radius = read_int_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.color.r", i);
		s->objs[i].color.r = read_color_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.color.g", i);
		s->objs[i].color.g = read_color_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.color.b", i);
		s->objs[i].color.b = read_color_data(data, request);
		free(request);
		request = construct_request_int("spheres.#.reflection", i);
		s->objs[i].refl = read_color_data(data, request);
		free(request);
		s->objs[i].type = SPHERE;
		++i;
	}
}
