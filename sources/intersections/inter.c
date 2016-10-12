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

void	intersect_objects(t_env *e, t_ray *ray, t_intersection *inter)
{
	int		i;
	double	z;

	i = 0;
	z = RAY_END + 1;
	while (i < e->scene->n_obj)
	{
		if (e->scene->objs[i].type == SPHERE)
		{
			//ft_putendl("mdrlol");
			inter_spheres(ray, &e->scene->objs[i], &z);
		}
		else if (e->scene->objs[i].type == CYLINDER)
			inter_cylinders(ray, &e->scene->objs[i], &z);
		else if (e->scene->objs[i].type == CONE)
			inter_cones(ray, &e->scene->objs[i], &z);
		else if (e->scene->objs[i].type == PLANE)
			inter_planes(ray, &e->scene->objs[i], &z);
		if (z < inter->z)
		{
			//ft_putnbr_endl((int)z);
			inter->obj = &e->scene->objs[i];
			inter->z = z;
			inter->type = e->scene->objs[i].type;
		}
		++i;

		// if (test_hit(ray, &e->scene->spheres[i], &z))
		// {
		// 	if (z < RAY_END)
		// 	{
		// 		if (!inter->sphere)
		// 		{
		// 			inter->sphere = &e->scene->spheres[i];
		// 			inter->z_sphere = z;
		// 		}
		// 		else
		// 		{
		// 			if (z < inter->z_sphere)
		// 			{
		// 				inter->sphere = &e->scene->spheres[i];
		// 				inter->z_sphere = z;
		// 			}
		// 		}
		// 	}
		// }
		// ++i;
	}
}
