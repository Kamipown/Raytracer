/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:52:44 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/07 16:19:08 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// static double			deg_to_rad(double a)
// {
// 	return (a * M_PI / 180);
// }

// static void				rotate(t_vec3 *v)
// {
// 	t_vec3	t;

// 	t.x = v->x;
// 	t.y = v->y;
// 	t.z = v->z;
// 	v->x = t.x * cos(deg_to_rad(45)) + t.z * sin(deg_to_rad(45));
// 	v->z = t.x * -(sin(deg_to_rad(45))) + t.z * cos(deg_to_rad(45));
// }

void	create_ray(t_scene *scene, t_vec3 to)
{
	scene->ray.origin.x = scene->cam.pos.x;
	scene->ray.origin.y = scene->cam.pos.y;
	scene->ray.origin.z = scene->cam.pos.z;
	scene->ray.dir.x = to.x;
	scene->ray.dir.y = to.y;
	scene->ray.dir.z = scene->cam.focal_dist;
	vec_normalize(&scene->ray.dir);
}

static t_intersection	*create_intersection(void)
{
	t_intersection	*inter;

	if (!(inter = malloc(sizeof(t_intersection))))
		error(-17, "Unable to create intersection.");
	inter->obj = 0;
	inter->type = 0;
	inter->t = RAY_END + 1;
	return (inter);
}

t_intersection			*throw_ray(t_env *e, t_ray *ray, int flag)
{
	t_intersection	*inter;

	// if (flag == 1)
	// {
	// 	printf("Camera:\nposition(%f, %f, %f)\ndirection(%f, %f, %f)\n\n",
	// 		ray->origin.x, ray->origin.y, ray->origin.z,
	// 		ray->dir.x, ray->dir.y, ray->dir.z);
	// }

	inter = create_intersection();
	intersect_objects(e, ray, inter, flag);
	return (inter);
}
