/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:18:06 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/04 01:19:10 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			clean_spheres(t_scene *s)
{
	int				i;

	i = 0;
	while (i < s->n_obj)
	{
		if (s->objs[i].type == SPHERE)
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

static void			fill_spheres_data2(t_scene *s, char *data, int i)
{
	s->objs[i].radius =
		data_get_i_constructed(data, "spheres.#.radius", i);
	s->objs[i].color.r =
		data_get_i_constructed(data, "spheres.#.color.r", i);
	s->objs[i].color.g =
		data_get_i_constructed(data, "spheres.#.color.g", i);
	s->objs[i].color.b =
		data_get_i_constructed(data, "spheres.#.color.b", i);
	s->objs[i].refl =
		data_get_i_constructed(data, "spheres.#.reflection", i);
	s->objs[i].textures =
		data_get_i_constructed(data, "spheres.#.textures", i);
	s->objs[i].bump =
		data_get_d_constructed(data, "spheres.#.bump", i);
}

void				fill_spheres_data(t_scene *s, char *data, int counts[4])
{
	int				i;

	i = 0;
	while (i < counts[0])
	{
		s->objs[i].pos.x =
			data_get_i_constructed(data, "spheres.#.pos.x", i);
		s->objs[i].pos.y =
			data_get_i_constructed(data, "spheres.#.pos.y", i);
		s->objs[i].pos.z =
			data_get_i_constructed(data, "spheres.#.pos.z", i);
		fill_spheres_data2(s, data, i);
		s->objs[i].type = SPHERE;
		s->objs[i].id = i;
		++i;
	}
	clean_spheres(s);
}
