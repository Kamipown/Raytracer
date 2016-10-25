/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 10:36:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/20 15:37:20 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			*fill_counts_data(t_scene *s, char *data)
{
	int		*counts;

	counts = 0;
	if (!(counts = (int *)malloc(sizeof(int) * 4)))
		error(-1000, "Count error.");
	s->n_light = read_int_data(data, "config.counts.lights");
	s->n_light = s->n_light < 0 || s->n_light > 100 ? 0 : s->n_light;
	s->lights = (t_light *)malloc(sizeof(t_light) * s->n_light);
	counts[0] = read_int_data(data, "config.counts.spheres");
	counts[1] = read_int_data(data, "config.counts.cylinders");
	counts[2] = read_int_data(data, "config.counts.cones");
	counts[3] = read_int_data(data, "config.counts.planes");
	counts[0] = counts[0] < 0 || counts[0] > 100 ? 0 : counts[0];
	counts[1] = counts[1] < 0 || counts[1] > 100 ? 0 : counts[1];
	counts[2] = counts[2] < 0 || counts[2] > 100 ? 0 : counts[2];
	counts[3] = counts[3] < 0 || counts[3] > 100 ? 0 : counts[3];
	s->n_obj = counts[0] + counts[1] + counts[2] + counts[3];
	s->objs = (t_obj *)malloc(sizeof(t_obj) * s->n_obj);
	if (!s->lights || !s->objs)
		error(-11, "Unable to create objects.");
	return (counts);
}

void		fill_camera_data(t_scene *s, char *data)
{
	if (!(s->cam = (t_cam *)malloc(sizeof(t_cam))))
		error(-16, "Unable to create camera.");
	s->cam->fov = read_int_data(data, "config.camera.fov");
	s->cam->fov = s->cam->fov < 1 || s->cam->fov > 90 ? FOV : s->cam->fov;
	s->cam->focal_dist = (s->size.w / 2 / (fabs(tan(s->cam->fov / 2))));
	s->cam->pos = (t_vec3){0, 0, -s->cam->focal_dist};
}

void		fill_screen_data(t_scene *s, char *data)
{
	int		sw;
	int		sh;

	sw = read_int_data(data, "config.screen.width");
	sh = read_int_data(data, "config.screen.height");
	s->size.w = sw >= MIN_SCREEN_W && sw <= MAX_SCREEN_W ? sw : SCREEN_W;
	s->size.h = sh >= MIN_SCREEN_H && sh <= MAX_SCREEN_H ? sh : SCREEN_H;
}

void		fill_light_data(t_scene *s, char *data)
{
	s->exposure = read_double_data(data, "config.light.exposure");
}
