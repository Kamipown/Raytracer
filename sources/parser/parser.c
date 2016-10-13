/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:25:27 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/13 21:53:02 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_scene *s, char *filename)
{
	char	*data;
	int		*counts;

	data = read_file(filename);
	fill_screen_data(s, data);
	fill_camera_data(s, data);
	counts = fill_counts_data(s, data);
	fill_lights_data(s, data);
	fill_spheres_data(s, data, counts);
	fill_cylinders_data(s, data, counts);
	fill_cones_data(s, data, counts);
	fill_planes_data(s, data, counts);
	free(counts);
	free(data);
	
}