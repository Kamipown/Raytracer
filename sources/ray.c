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

// void	update_ray(t_ray *ray, t_vec3 target)
// {
// 	vec_normalize(&target);
// 	ray->dir.x = target.x - ray->origin.x;
// 	ray->dir.y = target.y - ray->origin.y;
// 	ray->dir.z = target.z - ray->origin.z;
// 	vec_normalize(&ray->dir);
// }

// t_ray	*init_ray(t_vec3 *cam_pos)
// {
// 	t_ray	*ray;
//
// 	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
// 		error(-16, "Unable to create ray.");
// 	ray->origin.x = cam_pos->x;
// 	ray->origin.y = cam_pos->y;
// 	ray->origin.z = cam_pos->z;
// 	return (ray);
// }

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
