/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:52:44 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/03 23:53:19 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void				apply_rotations(t_scene *s)
{
	double	t;

	t = s->ray.dir.y;
	s->ray.dir.y = s->ray.dir.y * cos(deg_to_rad(s->cam.rot.x)) + s->ray.dir.z
					* -(sin(deg_to_rad(s->cam.rot.x)));
	s->ray.dir.z = t * sin(deg_to_rad(s->cam.rot.x)) + s->ray.dir.z
					* cos(deg_to_rad(s->cam.rot.x));
	t = s->ray.dir.x;
	s->ray.dir.x = s->ray.dir.x * cos(deg_to_rad(s->cam.rot.y)) + s->ray.dir.z
					* sin(deg_to_rad(s->cam.rot.y));
	s->ray.dir.z = t * -(sin(deg_to_rad(s->cam.rot.y))) + s->ray.dir.z
					* cos(deg_to_rad(s->cam.rot.y));
	t = s->ray.dir.x;
	s->ray.dir.x = s->ray.dir.x * cos(deg_to_rad(s->cam.rot.z)) + s->ray.dir.y
					* -(sin(deg_to_rad(s->cam.rot.z)));
	s->ray.dir.y = t * sin(deg_to_rad(s->cam.rot.z)) + s->ray.dir.y
					* cos(deg_to_rad(s->cam.rot.z));
}

void					create_ray(t_scene *scene, t_vec3 to)
{
	scene->ray.origin.x = scene->cam.pos.x;
	scene->ray.origin.y = scene->cam.pos.y;
	scene->ray.origin.z = scene->cam.pos.z;
	scene->ray.dir.x = to.x;
	scene->ray.dir.y = to.y;
	scene->ray.dir.z = scene->cam.focal_dist;
	vec_normalize(&scene->ray.dir);
	apply_rotations(scene);
}

static t_intersection	create_intersection(void)
{
	t_intersection	inter;

	inter.obj = 0;
	inter.type = 0;
	inter.t = RAY_END + 1;
	return (inter);
}

t_intersection			throw_ray(t_env *e, t_ray *ray)
{
	t_intersection	inter;

	inter = create_intersection();
	intersect_objects(e, ray, &inter);
	return (inter);
}
