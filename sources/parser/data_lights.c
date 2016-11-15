/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 11:01:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/15 02:44:01 by gromon           ###   ########.fr       */
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
		s->lights[i].dir.x = interval_d(s->lights[i].dir.x, -1.0, 1.0);
		s->lights[i].dir.y = interval_d(s->lights[i].dir.y, -1.0, 1.0);
		s->lights[i].dir.z = interval_d(s->lights[i].dir.z, -1.0, 1.0);
		s->lights[i].color.r /= 255.0;
		s->lights[i].color.g /= 255.0;
		s->lights[i].color.b /= 255.0;
		s->lights[i].intensity = interval_i(s->lights[i].intensity, 0, 200);
		s->lights[i].intensity /= 100.0;
		++i;
	}
	s->ambient.r = interval_d(s->ambient.r, 0.0, 255.0);
	s->ambient.g = interval_d(s->ambient.g, 0.0, 255.0);
	s->ambient.b = interval_d(s->ambient.b, 0.0, 255.0);
	s->ambient.r /= 255.0;
	s->ambient.g /= 255.0;
	s->ambient.b /= 255.0;
	s->brightness = interval_i(s->brightness, 0, 359);
}

static void		fill_lights_data2(t_scene *s, char *data, int i)
{
	s->lights[i].dir.x =
		data_get_d_constructed(data, "lights.#.dir.x", i);
	s->lights[i].dir.y =
		data_get_d_constructed(data, "lights.#.dir.y", i);
	s->lights[i].dir.z =
		data_get_d_constructed(data, "lights.#.dir.z", i);
	s->lights[i].type =
		data_get_i_constructed(data, "lights.#.type", i);
	s->lights[i].radius =
		data_get_d_constructed(data, "lights.#.radius", i);
	s->lights[i].intensity =
		data_get_i_constructed(data, "lights.#.intensity", i);
}

static void		fill_lights_config(t_scene *s, char *data)
{
	s->ambient.r = read_double_data(data, "config.lighting.ambient.r");
	s->ambient.g = read_double_data(data, "config.lighting.ambient.g");
	s->ambient.b = read_double_data(data, "config.lighting.ambient.b");
	s->brightness = read_int_data(data, "config.lighting.brightness");
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
	fill_lights_config(s, data);
	clean_lights(s);
}
