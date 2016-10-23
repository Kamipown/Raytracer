/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cylinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:18:06 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/23 04:36:55 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void clean_cylinders(t_scene *s)
{
	int		i;

	i = 0;
	while (i < s->n_obj)
	{
		if (s->objs[i].type == CYLINDER)
		{
			s->objs[i].color.r = interval_d(s->objs[i].color.r, 0.0, 255.0);
			s->objs[i].color.g = interval_d(s->objs[i].color.g, 0.0, 255.0);
			s->objs[i].color.b = interval_d(s->objs[i].color.b, 0.0, 255.0);
			s->objs[i].refl = interval_d(s->objs[i].refl, 0.0, 100.0);
			s->objs[i].color.r /= 255.0;
			printf("r-> %f\n", s->objs[i].color.r);
			s->objs[i].color.g /= 255.0;
			printf("g-> %f\n", s->objs[i].color.g);
			s->objs[i].color.b /= 255.0;
			printf("b-> %f\n", s->objs[i].color.b);
			s->objs[i].refl /= 100;
			printf("%f\n", s->objs[i].color.r);
		}
		++i;
	}
}

void		fill_cylinders_data(t_scene *s, char *data, int counts[4])
{
	int		i;
	int		j;

	i = 0;
	j = counts[0];
	while (i < counts[1])
	{
		s->objs[i + j].pos.x = 
				data_get_i_constructed(data, "cylinders.#.pos.x", i);
				printf("%f", s->objs[i + j].pos.x );
		s->objs[i + j].pos.y = 
				data_get_i_constructed(data, "cylinders.#.pos.y", i);
		s->objs[i + j].pos.z = 
				data_get_i_constructed(data, "cylinders.#.pos.z", i);
		s->objs[i + j].rot.x = 
				data_get_i_constructed(data, "cylinders.#.normal.x", i);
		s->objs[i + j].rot.y = 
				data_get_i_constructed(data, "cylinders.#.normal.y", i);
		s->objs[i + j].rot.z = 
				data_get_i_constructed(data, "cylinders.#.normal.z", i);
		s->objs[i + j].radius =
				data_get_i_constructed(data, "cylinders.#.radius", i);
		s->objs[i + j].color.r =
				data_get_i_constructed(data, "cylinders.#.color.r", i);
		s->objs[i + j].color.g =
				data_get_i_constructed(data, "cylinders.#.color.g", i);
		s->objs[i + j].color.b =
				data_get_i_constructed(data, "cylinders.#.color.b", i);
		s->objs[i + j].refl =
				data_get_i_constructed(data, "cylinder.#.reflection", i);
		s->objs[i + j].type = CYLINDER;
		s->objs[i + j].id = i + j;
		++i;
	}
	clean_cylinders(s);
}
