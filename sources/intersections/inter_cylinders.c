/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/10 02:20:32 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	test_hit(t_ray *ray, t_cylinder *c)
{
	double 	uZ;
	double 	d;
	double 	delta;
	double 	l;
	double 	a;
	double 	z1;
	double 	z2;


	uZ = ray->dir.z * ray->dir.z;
	d = (t_vec3){ray->dir.y, -ray->dir.x, 0} * ray->origin.z;
	delta = (c->radius * c->radius) * (ray->dir.z * ray-dir.z) - (d * d);
	
	if (delta < 0)
	{
		return (0);
	}

	l = ray->dir.z * ray->origin.z;
	a = vec_mul_to_d(ray->origin, ray->origin.z);

	if (l > 0 && a > (c->radius * c->radius))
	{
		return (0)
	}

}

void		inter_cylinders(t_env *e, t_ray *ray, t_intersection *inter)
{
	// int		i;

	// i = 0;
	// while (i < e->scene->n_cylinder)
	// {
	// 	if (test_hit(ray, &e->scene->cylinders[i]))
	// 	{
	// 		draw_pixel(e, (t_pixel){x, y, e->scene->spheres[i].color});
	// 		return (&e->scene->cylinders[i]);
	// 	}
	// 	++i;
	// }
	// return (0);
	if (e && ray && inter)
		;
}
