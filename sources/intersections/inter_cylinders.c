/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/23 04:22:48 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	inter_cylinders(t_ray *ray, t_obj *c, double *t)
{
	t_equation	e;
	t_vec3 		l;
	double 		x;
	double		y;

	c->rot = (t_vec3){0, 1, 0};
	l = vec_sub(ray->origin, c->pos);
	x = vec_mul_to_d(ray->dir, c->rot);
	y = vec_mul_to_d(l, c->rot);
	e.a = vec_mul_to_d(ray->dir, ray->dir) - (x * x);
	e.b = 2 * (vec_mul_to_d(ray->dir, l) - (x * y));
	e.c = vec_mul_to_d(l, l) - (c->radius * c->radius);

	e.delta = e.b * e.b - 4 * e.a * e.c;
	if (e.delta >= 0)
	{
			e.z1 = (-e.b + sqrt(e.delta)) / (2.0 * e.a);
			e.z2 = (-e.b - sqrt(e.delta)) / (2.0 * e.a);
			*t = (e.z1 < e.z2) ? e.z1 : e.z2;
			return (TRUE);
	}
	else
		return (FALSE);
}
