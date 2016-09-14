/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/03 19:40:22 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	throw_ray(t_env *e, t_ray *ray)
{
	if (inter_spheres(e, ray))
		return ;
	// if (inter_cylinder(e, ray))
	// 	return ;
	// if (inter_cones(e, ray))
	// 	return ;
	// if (inter_planes(e, ray))
	// 	return ;
}

void		raytrace(t_env *e)
{
	int		x;
	int		y;
	t_ray	*ray;

	printf("%d %d | %d %d | %d %d\n", e->scene->size.w, e->scene->size.h, e->scene->size.s_x, e->scene->size.s_y, e->scene->size.e_x, e->scene->size.e_y);
	ray = init_ray();
	y = e->scene->size.s_y;
	while (y < e->scene->size.e_y)
	{
		x = e->scene->size.s_x;
		while (x < e->scene->size.e_x)
		{
			update_ray(ray, x, y);
			throw_ray(e, ray);
			++x;
		}
		++y;
	}
	free(ray);
}
