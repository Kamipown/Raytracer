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

t_ray					*create_ray(t_vec3 *from, t_vec3 to)
{
	t_ray	*ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		error(-16, "Unable to create ray.");
	ray->origin.x = from->x;
	ray->origin.y = from->y;
	ray->origin.z = from->z;
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
	inter->z_sphere = RAY_END + 1;
	inter->z_cylinder = RAY_END + 1;
	inter->z_cone = RAY_END + 1;
	inter->z_plane = RAY_END + 1;
	return (inter);
}

static void				select_intersection(t_intersection *inter, int flag)
{
	if (inter->sphere)
	{
		if (flag == 1)
			printf("z_sphere: %f, ", inter->z_sphere);
		if (inter->z_sphere < inter->z_cylinder
		&& inter->z_sphere < inter->z_cone
		&& inter->z_sphere < inter->z_plane)
			inter->shape_type = SPHERE;
	}
	if (inter->cylinder)
	{
		if (inter->z_cylinder < inter->z_sphere
		&& inter->z_cylinder < inter->z_cone
		&& inter->z_cylinder < inter->z_plane)
			inter->shape_type = CYLINDER;
	}
	if (inter->cone)
	{
		if (inter->z_cone < inter->z_sphere
		&& inter->z_cone < inter->z_cylinder
		&& inter->z_cone < inter->z_plane)
			inter->shape_type = CONE;
	}
	if (inter->plane)
	{
		if (flag == 1)
			printf("z_plane: %f\n", inter->z_plane);
		if (inter->z_plane < inter->z_sphere
		&& inter->z_plane < inter->z_cylinder
		&& inter->z_plane < inter->z_cone)
			inter->shape_type = PLANE;
	}
}

t_intersection			*throw_ray(t_env *e, t_ray *ray, int flag)
{
	t_intersection	*inter;

	inter = create_intersection();
	inter_spheres(e, ray, inter);
	inter_cylinders(e, ray, inter);
	inter_cones(e, ray, inter);
	inter_planes(e, ray, inter);
	select_intersection(inter, flag);
	return (inter);
}
