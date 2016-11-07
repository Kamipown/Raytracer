/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:25:27 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/07 01:20:04 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_scene *s, char *filename)
{
	char	*data;
	int		*counts;

	data = read_file(filename);
	fill_screen_data(s, data);
	fill_light_data(s, data);
	fill_camera_data(s, data);
	counts = fill_counts_data(s, data);
	fill_lights_data(s, data);
	fill_spheres_data(s, data, counts);
	fill_cylinders_data(s, data, counts);
	fill_cones_data(s, data, counts);
	fill_planes_data(s, data, counts);
	free(counts);
	free(data);

	int i = 0;
	while (i < s->n_light)
	{
		printf("position: %f, %f, %f\ndirection: %f, %f, %f\ntype: %d\n",
		s->lights[i].pos.x,
		s->lights[i].pos.y,
		s->lights[i].pos.z,
		s->lights[i].dir.x,
		s->lights[i].dir.y,
		s->lights[i].dir.z,
		s->lights[i].type
		);
		++i;
	}
}
