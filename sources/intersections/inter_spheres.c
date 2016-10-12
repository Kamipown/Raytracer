/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:42:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/12 17:01:44 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	inter_spheres(t_ray *ray, t_obj *s, double *z)
{
	t_equation 		e;

	e.a = ray->dir.x * ray->dir.x 
		+ ray->dir.y * ray->dir.y
		+ ray->dir.z * ray->dir.z;

	e.b = ray->dir.x * (ray->origin.x - s->pos.x) 
		+ ray->dir.y * (ray->origin.y - s->pos.y)
		+ ray->dir.z * (ray->origin.z - s->pos.z);
	e.b *= 2.0;

	e.c = (ray->origin.x - s->pos.x) * (ray->origin.x - s->pos.x) 
		+ (ray->origin.y - s->pos.y) * (ray->origin.y - s->pos.y)
		+ (ray->origin.z - s->pos.z) * (ray->origin.z - s->pos.z);
	e.c -= (s->radius * s->radius);

	e.delta = (e.b * e.b - (4 * e.a * e.c));
	
	if (e.delta < 0.0)
		return ;

	e.z1 = ray->origin.z + ((-e.b + sqrt(e.delta)) / (2.0 * e.a)) * ray->dir.z;
	e.z2 = ray->origin.z + ((-e.b - sqrt(e.delta)) / (2.0 * e.a)) * ray->dir.z;

	if (e.z1 > 0.1 && e.z1 > 0.000001)
		*z = e.z1;
	if (e.z2 > 0.1 && e.z2 > 0.000001 && e.z2 < e.z1)
		*z = e.z2;
}
