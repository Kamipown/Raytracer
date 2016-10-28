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

static void	clean_cones(t_scene *s)
	{
		int		i;

		i = 0;
		
		while (i < s->n_obj)
		{
			if (s->objs[i].type == CONE)
			{
				s->objs[i].color.r = interval_d(s->objs[i].color.r, 0.0, 255.0);
				s->objs[i].color.g = interval_d(s->objs[i].color.g, 0.0, 255.0);
				s->objs[i].color.b = interval_d(s->objs[i].color.b, 0.0, 255.0);
				s->objs[i].refl = interval_d(s->objs[i].refl, 0.0, 100.0);
				s->objs[i].color.r /= 255.0;
				s->objs[i].color.g /= 255.0;
				s->objs[i].color.b /= 255.0;
				s->objs[i].refl /= 100;
			}
			++i;
		}
	}

void		fill_cones_data(t_scene *s, char *data, int counts[4])
{
	int		i;
	int		j;

	i = 0;
	j = counts[0] + counts[1];
	while (i < counts[2])
	{
		s->objs[i + j].pos.x =
			data_get_i_constructed(data, "cones.#.pos.x", i);
		s->objs[i + j].pos.y =
			data_get_i_constructed(data, "cones.#.pos.y", i);
		s->objs[i + j].pos.z =
			data_get_i_constructed(data, "cones.#.pos.z", i);
		s->objs[i + j].rot.x =
			data_get_d_constructed(data, "cones.#.normal.x", i);
		s->objs[i + j].rot.y =
			data_get_d_constructed(data, "cones.#.normal.y", i);
		s->objs[i + j].rot.z =
			data_get_d_constructed(data, "cones.#.normal.z", i);
		s->objs[i + j].radius =
			data_get_i_constructed(data, "cones.#.radius", i);
		s->objs[i + j].color.r =
			data_get_i_constructed(data, "cones.#.color.r", i);
		s->objs[i + j].color.g =
			data_get_i_constructed(data, "cones.#.color.g", i);
		s->objs[i + j].color.b =
			data_get_i_constructed(data, "cones.#.color.b", i);
		s->objs[i + j].refl =
			data_get_i_constructed(data, "cones.#.reflection", i);
		s->objs[i + j].textures =
			data_get_i_constructed(data, "cones.#.textures", i);
		s->objs[i + j].bump =
			data_get_d_constructed(data, "cones.#.bump", i);
		s->objs[i + j].type = CONE;
		s->objs[i + j].id = i;
		++i;
	}
	clean_cones(s);
}
