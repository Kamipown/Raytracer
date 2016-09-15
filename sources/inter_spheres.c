/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:42:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/14 14:42:50 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#include <stdio.h>
static int	test_hit(t_ray *ray, t_sphere *s)
{
	t_vec3	dist;
	float	b;
	float	d;
	float	z1;
	float	z2;

	dist.x = s->pos.x - ray->start.x;
	dist.y = s->pos.y - ray->start.y;
	dist.z = s->pos.z - ray->start.z;

	b = ray->dir.x * dist.x + ray->dir.y * dist.y + ray->dir.z * dist.z;
	d = b * b - (dist.x * dist.x + dist.y * dist.y + dist.z * dist.z) + s->radius * s->radius;
	if (d < 0.0f)
		return (0);

	//printf("pos(%d, %d, %d), radius(%d).\n", s->pos.x, s->pos.y, s->pos.z, s->radius);

	z1 = b - sqrtf(d);
	z2 = b + sqrtf(d);
	if (z1 > 0.1f && z1 < RAY_END)
	{
		return (1);
	}
	if (z2 > 0.0f && z2 < z1)
	{
		return (1);
	}
	return (0);
}

int			inter_spheres(t_env *e, t_ray *ray)
{
	int		i;

	i = 0;
	while (i < e->scene->n_sphere)
	{
		if (test_hit(ray, &e->scene->spheres[i]))
		{
			draw_pixel(e, (t_pixel){ray->start.x, ray->start.y, e->scene->spheres[i].color});
			return (1);
		}
		++i;
	}
	return (0);
}
