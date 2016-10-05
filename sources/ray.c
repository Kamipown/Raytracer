/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:52:44 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 16:06:57 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray					*create_ray(t_vec3 *from, t_vec3 to)
{
	t_ray	*ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		error(-16, "Unable to create ray.");
	ray->origin.x = from->x;
	ray->origin.y = from->y;
	ray->origin.z = from->z;
	vec_normalize(&to);
	ray->dir.x = to.x - ray->origin.x;
	ray->dir.y = to.y - ray->origin.y;
	ray->dir.z = to.z - ray->origin.z;
	vec_normalize(&ray->dir);
	return (ray);
}

static t_intersection	*create_intersection(void)
{
	t_intersection	*inter;

	if (!(inter = malloc(sizeof(t_intersection))))
		error(-17, "Unable to create intersection.");
	inter->sphere = 0;
	inter->cylinder = 0;
	inter->cone = 0;
	inter->plane = 0;
	inter->shape_type = 0;
	return (inter);
}

t_intersection			*throw_ray(t_env *e, t_ray *ray, int x, int y)
{
	t_intersection	*inter;

	inter = create_intersection();
	if ((inter->sphere = inter_spheres(e, ray, x, y)))
		inter->shape_type = SPHERE;
	if ((inter->cylinder = inter_cylinders(e, ray)))
		inter->shape_type = CYLINDER;
	if ((inter->cone = inter_cones(e, ray)))
		inter->shape_type = CONE;
	if ((inter->plane = inter_planes(e, ray)))
		inter->shape_type = PLANE;
	return (inter);
}
