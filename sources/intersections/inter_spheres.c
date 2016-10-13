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

t_bool	inter_spheres(t_ray *ray, t_obj *s, double *z, double *t)
{
	t_equation 		e;
	t_bool			ret;

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
		return (FALSE);

	e.z1 = (-e.b + sqrt(e.delta)) / (2.0 * e.a);
	e.z2 = (-e.b - sqrt(e.delta)) / (2.0 * e.a);

	ret = FALSE;
	if (e.z1 > 0.1 && e.z1 > 0.000001)
	{
		*t = e.z1;
		*z = ray->origin.z + e.z1 * ray->dir.z;
		ret = TRUE;
	}
	if (e.z2 > 0.1 && e.z2 > 0.000001 && e.z2 < e.z1)
	{
		*t = e.z2;
		*z = ray->origin.z + e.z2 * ray->dir.z;
		ret = TRUE;
	}
	return (ret);
}
