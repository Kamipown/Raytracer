/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:42:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/20 16:06:42 by opettex-         ###   ########.fr       */
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

	dist = vec_sub(&s->pos, &ray->origin);
	b = vec_mul_to_f(&ray->dir, &dist);
	d = b * b - vec_mul_to_f(&dist, &dist) + s->radius * s->radius;
	if (d < 0.0f)
		return (0);
	z1 = b - sqrtf(d);
	z2 = b + sqrtf(d);
	// ft_putnbr_endl(z1);
	// ft_putnbr_endl(z2);
	// Verifier que (z1 || z2 > 0.1f)
	// prendre le plus proche
	// en faisant attention a RAY_END
	//
	if (z1 > 0.1f && z1 < RAY_END)
		return (1);
	if (z2 > 0.0f && z2 < z1)
		return (1);
	return (0);
}

t_sphere	*inter_spheres(t_env *e, t_ray *ray, int x, int y)
{
	int		i;

	i = 0;
	while (i < e->scene->n_sphere)
	{
		if (test_hit(ray, &e->scene->spheres[i]))
		{
			draw_pixel(e, (t_pixel){x, y, e->scene->spheres[i].color});
			return (&e->scene->spheres[i]);
		}
		++i;
	}
	return (0);
}
