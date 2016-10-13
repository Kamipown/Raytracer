/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 11:01:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/29 11:01:16 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	clean_lights(t_scene *s)
{
	int		i;

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

void		fill_lights_data(t_scene *s, char *data)
{
	int		i;

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
		s->lights[i].intensity =
			data_get_i_constructed(data, "lights.#.intensity", i);
		++i;
	}
	clean_lights(s);
}
