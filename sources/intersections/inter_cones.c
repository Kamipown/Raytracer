/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/10/12 23:07:40 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	test_hit(t_ray *ray, t_cone *c, double *z)
{
	t_equation 		e;
	unsigned int	ret;
	// double 			angle;
	double 			h;
	double 			s;
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

	h = 20;
	s = pow(c->radius, 2) / pow(h, 2);
	e.a = (ray->dir.x * ray->dir.x)
	+ (ray->dir.y * ray->dir.y)
	- s * (ray->dir.z * ray->dir.z);

	e.b = 2 * ((ray->origin.x * ray->dir.x) 
	+ (ray->origin.y * ray->dir.y)
	- s * ((ray->origin.z - h) * ray->dir.z));

	e.c = (ray->origin.x * ray->origin.x) 
	+ (ray->origin.y * ray->origin.y)
	- s * (ray->origin.z - h * ray->origin.z - h);

	e.delta = DELTA;

	e.z1 = -Z1;
	e.z2 = -Z2;

	if (e.delta < 0)
	{
		return (0);
	}
	else if (e.delta == 0)
	{
		printf("mdr");
		e.z1 = - e.b / 2 * e.a;
		*z = e.z1;
	}

	ret = FALSE;
	
	if (e.z1 > 0)
	{
		*z = e.z1;
		ret = TRUE;
	}
	if (e.z2 > 0 && e.z2 > 0.000000 && e.z2 < e.z1)
	{
		*z = e.z2;
		ret = TRUE;
	}
	return (ret);
}

void		inter_cones(t_env *e, t_ray *ray, t_intersection *inter)
{
	int		i;
	double	z;

	i = 0;
	while (i < e->scene->n_cone)
	{
		if (test_hit(ray, &e->scene->cones[i], &z))
		{
			if (z < RAY_END)
			{
				if (!inter->cone)
				{
					inter->cone = &e->scene->cones[i];
					inter->z_cone = z;
				}
				else
				{
					if (z < inter->z_cone)
					{
						inter->cone = &e->scene->cones[i];
						inter->z_cone = z;
					}
				}
			}
		}
		++i;
	}
}
