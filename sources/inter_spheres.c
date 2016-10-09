/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:42:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 16:06:12 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static int	test_hit(t_ray *ray, t_sphere *s, double *z)
{
	t_vec3	dist;
	double	b;
	double	d;
	double	z1;
	double	z2;

	dist = vec_sub(&s->pos, &ray->origin);
	b = vec_mul_to_d(&ray->dir, &dist);
	d = b * b - vec_mul_to_d(&dist, &dist) + s->radius * s->radius;
	if (d < 0.0)
		return (0);
	z1 = b - sqrtf(d);
	z2 = b + sqrtf(d);
	// ft_putnbr_endl(z1);
	// ft_putnbr_endl(z2);
	// Verifier que (z1 || z2 > 0.1f)
	// prendre le plus proche
	// en faisant attention a RAY_END
	//
	if (z1 > 0.1 && z1 < RAY_END)
	{
		*z = z1;
		//printf("z1: %f\n", z1);
		return (1);
	}
	if (z2 > 0.0 && z2 < z1)
	{
		*z = z2;
		//printf("z2: %f\n", z2);
		return (1);
	}
	return (0);
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
			if (z >= 0.000001 && z < RAY_END)
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
