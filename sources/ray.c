/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:52:44 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/20 17:29:46 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	*create_ray(t_vec3 *from, t_vec3 to)
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

void	throw_ray(t_env *e, t_ray *ray, int x, int y)
{
	if (inter_spheres(e, ray, x, y))
		return ;
	if (inter_cylinders(e, ray))
		return ;
	if (inter_cones(e, ray))
		return ;
	if (inter_planes(e, ray))
		return ;
}
