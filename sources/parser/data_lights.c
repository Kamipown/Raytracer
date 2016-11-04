/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 11:01:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/04 03:31:36 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		clean_lights(t_scene *s)
{
	int			i;

	i = 0;
	while (i < s->n_light)
	{
		s->lights[i].color.r = interval_d(s->lights[i].color.r, 0.0, 255.0);
		s->lights[i].color.g = interval_d(s->lights[i].color.g, 0.0, 255.0);
		s->lights[i].color.b = interval_d(s->lights[i].color.b, 0.0, 255.0);
		s->lights[i].intensity = interval_d(s->lights[i].intensity, 0.0, 100.0);
		s->lights[i].color.r /= 255.0;
		s->lights[i].color.g /= 255.0;
		s->lights[i].color.b /= 255.0;
		s->lights[i].intensity /= 100.0;
		++i;
	}
}

static void		fill_lights_data2(t_scene *s, char *data, int i)
{
	s->lights[i].dir.x =
		data_get_i_constructed(data, "lights.#.dir.x", i);
	s->lights[i].dir.y =
		data_get_i_constructed(data, "lights.#.dir.y", i);
	s->lights[i].dir.z =
		data_get_i_constructed(data, "lights.#.dir.z", i);
	s->lights[i].intensity =
		data_get_i_constructed(data, "lights.#.intensity", i);
	s->lights[i].type =
		data_get_i_constructed(data, "lights.#.type", i);
	s->lights[i].radius =
		data_get_i_constructed(data, "lights.#.radius", i);
}

void			fill_lights_data(t_scene *s, char *data)
{
	int			i;

	i = 0;
	while (i < s->n_light)
	{
		s->lights[i].pos.x =
			data_get_i_constructed(data, "lights.#.pos.x", i);
		s->lights[i].pos.y =
			data_get_i_constructed(data, "lights.#.pos.y", i);
		s->lights[i].pos.z =
			data_get_i_constructed(data, "lights.#.pos.z", i);
		s->lights[i].color.r =
			data_get_i_constructed(data, "lights.#.color.r", i);
		s->lights[i].color.g =
			data_get_i_constructed(data, "lights.#.color.g", i);
		s->lights[i].color.b =
			data_get_i_constructed(data, "lights.#.color.b", i);
		fill_lights_data2(s, data, i);
		++i;
	}
	clean_lights(s);
}
