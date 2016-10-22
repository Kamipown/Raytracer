/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 00:11:09 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/13 00:11:10 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	intersect_objects(t_env *e, t_ray *ray, t_intersection *inter, int flag)
{
	int		i;
	double	t;

	i = 0;
	t = inter->t + 1000000;
	while (i < e->scene->n_obj)
	{
		if (e->scene->objs[i].type == SPHERE)
			inter_spheres(ray, &e->scene->objs[i], &t);
		else if (e->scene->objs[i].type == CYLINDER)
			inter_cylinders(ray, &e->scene->objs[i], &t);
		else if (e->scene->objs[i].type == CONE)
			inter_cones(ray, &e->scene->objs[i], &t);
		else if (e->scene->objs[i].type == PLANE)
			inter_planes(ray, &e->scene->objs[i], &t);
		if (t < inter->t && t > 0.00001)
		{
			inter->obj = &e->scene->objs[i];
			inter->type = e->scene->objs[i].type;
			inter->t = t;
		}
		++i;
	}
	if (flag && inter->obj)
	{
		printf("Intersection found:\n");
		printf("Ray start:     %f, %f, %f\n", ray->origin.x, ray->origin.y, ray->origin.z);
		printf("Ray direction: %f, %f, %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
		printf("T:             %f\n", inter->t);
		printf("T impact:      %f, %f, %f\n\n",
			ray->origin.x + ray->dir.x * inter->t,
			ray->origin.y + ray->dir.y * inter->t,
			ray->origin.z + ray->dir.z * inter->t);
	}
}
