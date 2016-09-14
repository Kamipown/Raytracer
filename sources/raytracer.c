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

// void		apply_lights(t_sphere *e->scene->spheres)
// {
	
// }

// int			inter_spheres()
// {
// 	if (intersection e->scene->spheres[3])
// 	{
// 		apply_lights(e->scene->spheres[3]);
// 		return (1);
// 	}
// 	return (0);
// }

static void	throw_ray(t_env *e, t_ray *ray)
{
	while (ray->pos.z <= RAY_END)
	{
		// if (inter_spheres(ray->pos, ))
		// 	return ;
		// if (inter_cylinder(ray->pos, ))
		// 	return ;
		if (e)
			++ray->pos.z;
	}
}

void		raytrace(t_env *e)
{
	int		x;
	int		y;
	t_ray	*ray;

	ray = init_ray();
	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			update_ray(ray, x, y);
			throw_ray(e, ray);
			++x;
		}
		++y;
	}
	free(ray);
}
