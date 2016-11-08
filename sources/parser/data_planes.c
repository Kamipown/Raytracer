/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 14:23:51 by dcognata          #+#    #+#             */
/*   Updated: 2016/11/07 21:13:33 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			clean_planes(t_scene *s)
{
	int				i;

	i = 0;
	while (i < s->n_obj)
	{
		if (s->objs[i].type == PLANE)
		{
			s->objs[i].color.r = interval_d(s->objs[i].color.r, 0.0, 255.0);
			s->objs[i].color.g = interval_d(s->objs[i].color.g, 0.0, 255.0);
			s->objs[i].color.b = interval_d(s->objs[i].color.b, 0.0, 255.0);
			s->objs[i].rot.x = interval_d(s->objs[i].rot.x, -1.0, 1.0);
			s->objs[i].rot.y = interval_d(s->objs[i].rot.y, -1.0, 1.0);
			s->objs[i].rot.z = interval_d(s->objs[i].rot.z, -1.0, 1.0);
			s->objs[i].refl = interval_d(s->objs[i].refl, 0.0, 100.0);
			s->objs[i].color.r /= 255.0;
			s->objs[i].color.g /= 255.0;
			s->objs[i].color.b /= 255.0;
			s->objs[i].refl /= 100;
		}
		++i;
	}
}

static void			fill_planes_data2(t_scene *s, char *data, int i, int j)
{
	s->objs[i + j].radius = 0;
	s->objs[i + j].color.r =
		data_get_i_constructed(data, "planes.#.color.r", i);
	s->objs[i + j].color.g =
		data_get_i_constructed(data, "planes.#.color.g", i);
	s->objs[i + j].color.b =
		data_get_i_constructed(data, "planes.#.color.b", i);
	s->objs[i + j].refl =
		data_get_i_constructed(data, "planes.#.reflection", i);
	s->objs[i + j].textures =
		data_get_i_constructed(data, "planes.#.textures", i);
	s->objs[i + j].bump =
		data_get_d_constructed(data, "planes.#.bump", i);
	s->objs[i + j].radius =
		data_get_i_constructed(data, "planes.#.size", i);
}

void				fill_planes_data(t_scene *s, char *data, int counts[4])
{
	int				i;
	int				j;

	i = 0;
	j = counts[0] + counts[1] + counts[2];
	while (i < counts[3])
	{
		s->objs[i + j].pos.x =
			data_get_i_constructed(data, "planes.#.pos.x", i);
		s->objs[i + j].pos.y =
			data_get_i_constructed(data, "planes.#.pos.y", i);
		s->objs[i + j].pos.z =
			data_get_i_constructed(data, "planes.#.pos.z", i);
		s->objs[i + j].rot.x =
			data_get_i_constructed(data, "planes.#.normal.x", i);
		s->objs[i + j].rot.y =
			data_get_i_constructed(data, "planes.#.normal.y", i);
		s->objs[i + j].rot.z =
			data_get_i_constructed(data, "planes.#.normal.z", i);
		fill_planes_data2(s, data, i, j);
		s->objs[i + j].type = PLANE;
		s->objs[i + j].id = i + j;
		++i;
	}
	clean_planes(s);
}
