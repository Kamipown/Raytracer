/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/10/12 20:50:10 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	inter_cones(t_ray *ray, t_obj *c, double *z)
{
	// t_equation 		e;
	// double 			angle;

	// angle = c->radius * (M_PI / 180);
	// e.a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y - ray->dir.z * ray->dir.z
	// 	* tan(angle) * tan(angle);
	// e.b = 2 * (ray->origin.x * ray->dir.x + ray->origin.y * ray->dir.y - ray->dir.x * c->pos.x
	// 	- ray->dir.y * c->pos.y + (ray->dir.z * (c->pos.z - ray->origin.z))
	// 		* tan(angle) * tan(angle));
	// e.c = ray->origin.x * ray->origin.x + ray->origin.y * ray->origin.y + c->pos.x * c->pos.x
	// 	+ c->pos.y * c->pos.y - 2 * (ray->origin.x * c->pos.x + ray->origin.y * c->pos.y)
	// 		- (ray->origin.z * ray->origin.z - 2 * (ray->origin.z * c->pos.z) + c->pos.z * c->pos.z)
	// 			* tan(angle) * tan(angle);

	// N = (t_vec3)
	// {
	// 	c->normal.x,
	// 	c->normal.y,
	// 	c->normal.z
	// };

	// e.a = (ray->dir.x * ray->dir.x)
	// - (ray->dir.y * ray->dir.y)
	// * pow(c->radius, 2)
	// + (ray->dir.z * ray->dir.z);

	// e.b = 2 * ((ray->origin.x * ray->dir.x) 
	// - (ray->origin.y * ray->dir.y))
	// * pow(c->radius, 2) 
	// + ((ray->origin.z * ray->dir.z));

	// e.c = (ray->origin.x * ray->origin.x) 
	// + (ray->origin.y * ray->origin.y)
	// - (ray->origin.z * ray->origin.z)
	// * pow(c->radius, 2);

	// e.delta = DELTA;

	// e.z1 = Z1;
	// e.z2 = Z2;

	// if (e.z1 > 0.0)
	// 	*z = e.z1;
	// if (e.z2 > 0.0 && e.z2 < e.z1)
	// 	*z = e.z2;
	if (ray && c && z)
		return (FALSE);
	return (FALSE);
}
