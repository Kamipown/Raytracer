/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/20 17:33:13 by dcognata         ###   ########.fr       */
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

	t_vec3	veca;
	t_vec3	vecb;
	t_vec3	vecdir;
	t_vec3	khey; // (ray)
	veca.x = 0;
	veca.y = 0;
	veca.z = 0;

	ray = init_ray();
	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			//point visay
			vecb.x = (e->scene->size.w / 2) - x;
			vecb.y = (e->scene->size.h / 2) - y;
			vecb.z = (2 * tan(e->scene->cam->fov / 2) / e->scene->size.w) * -1;
			vecb = vector_normalize(&vecb);
			vecdir.x = vecb.x - veca.x;
			vecdir.y = vecb.y - veca.y;
			vecdir.z = vecb.z - veca.z;
			vecdir = vector_normalize(&vecdir);
			printf("vecdir x-%f y-%f z-%f\n", vecdir.x, vecdir.y, vecdir.z);

			exit(0);
			update_ray(ray, x, y);
			throw_ray(e, ray);
			++x;
		}
		++y;
	}
	ft_putendl("raytrace");
	free(ray);
}
