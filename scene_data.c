/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 05:01:29 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/20 05:01:30 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	malloc_counts(t_scene *scene)
{
	if (scene->n_light)
		if (!(scene->lights =
			(t_light *)malloc(sizeof(t_light) * scene->n_light)))
			error(-9, "Unable to create lights.");
	if (scene->n_sphere)
		if (!(scene->spheres =
			(t_sphere *)malloc(sizeof(t_sphere) * scene->n_sphere)))
			error(-10, "Unable to create spheres.");
	if (scene->n_cylinder)
		if (!(scene->cylinders =
			(t_cylinder *)malloc(sizeof(t_cylinder) * scene->n_cylinder)))
			error(-11, "Unable to create cylinders.");
	if (scene->n_cone)
		if (!(scene->cones =
			(t_cone *)malloc(sizeof(t_cone) * scene->n_cone)))
			error(-12, "Unable to create cones.");
	if (scene->n_plane)
		if (!(scene->planes =
			(t_plane *)malloc(sizeof(t_plane) * scene->n_plane)))
			error(-13, "Unable to create planes.");
}

void		fill_counts_data(t_scene *scene, char *data)
{
	scene->n_light = read_int_data(data, "config.counts.lights");
	scene->n_sphere = read_int_data(data, "config.counts.spheres");
	scene->n_cylinder = read_int_data(data, "config.counts.cylinders");
	scene->n_cone = read_int_data(data, "config.counts.cones");
	scene->n_plane = read_int_data(data, "config.counts.planes");
	scene->n_light = scene->n_light < 0 ? 0 : scene->n_light;
	scene->n_sphere = scene->n_sphere < 0 ? 0 : scene->n_sphere;
	scene->n_cylinder = scene->n_cylinder < 0 ? 0 : scene->n_cylinder;
	scene->n_cone = scene->n_cone < 0 ? 0 : scene->n_cone;
	scene->n_plane = scene->n_plane < 0 ? 0 : scene->n_plane;
	ft_putnbr_endl(scene->n_light);
	ft_putnbr_endl(scene->n_sphere);
	ft_putnbr_endl(scene->n_cylinder);
	ft_putnbr_endl(scene->n_cone);
	ft_putnbr_endl(scene->n_plane);
	malloc_counts(scene);
}

void		fill_screen_data(t_scene *scene, char *data)
{
	int		sw;
	int		sh;

	sw = read_int_data(data, "config.screen.width");
	sh = read_int_data(data, "config.screen.height");
	scene->screen_w = sw >= MIN_SCREEN_W && sw <= MAX_SCREEN_W ? sw : SCREEN_W;
	scene->screen_h = sh >= MIN_SCREEN_H && sh <= MAX_SCREEN_H ? sh : SCREEN_H;
}
