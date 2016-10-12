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
#include <stdio.h>

static int	test_hit(t_ray *ray, t_sphere *s, double *z)
{
	t_equation 		e;
	unsigned int	ret;

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

	e.delta = DELTA;
	
	if (e.delta < 0.0)
		return (0);

	e.z1 = Z1;
	e.z2 = Z2;

	ret = FALSE;
	if (e.z1 > 0.1 && e.z1 > 0.000001)
	{
		*z = e.z1;
		ret = TRUE;
	}
	if (e.z2 > 0.1 && e.z2 > 0.000001 && e.z2 < e.z1)
	{
		*z = e.z2;
		ret = TRUE;
	}
	return (ret);
}

void		inter_spheres(t_env *e, t_ray *ray, t_intersection *inter)
{
	int		i;
	double	z;

	i = 0;
	while (i < e->scene->n_sphere)
	{
		if (test_hit(ray, &e->scene->spheres[i], &z))
		{
			if (z < RAY_END)
			{
				if (!inter->sphere)
				{
					inter->sphere = &e->scene->spheres[i];
					inter->z_sphere = z;
				}
				else
				{
					if (z < inter->z_sphere)
					{
						inter->sphere = &e->scene->spheres[i];
						inter->z_sphere = z;
					}
				}
			}
		}
		++i;
	}
}
