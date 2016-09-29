/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/21 14:21:04 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	throw_ray(t_env *e, t_ray *ray, int x, int y)
{
	if (inter_spheres(e, ray, x, y))
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
	
	ray = init_ray(&e->scene->cam->pos);
	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			update_ray(ray, (t_vec3)
			{
				x - (e->scene->size.w / 2),
				y - (e->scene->size.h / 2),
				e->scene->cam->focal_dist
			});
			throw_ray(e, ray, x, y);
			++x;
		}
		++y;
	}
	free(ray);
}
