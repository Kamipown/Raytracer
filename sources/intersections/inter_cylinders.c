/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/14 03:46:27 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool			inter_cylinders(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_vec3		p;

	p = vec_sub(ray->origin, s->pos);
	vec_rotate(&p, s->rot);
	vec_rotate(&ray->dir, s->rot);
	e.a = (ray->dir.x * ray->dir.x) + (ray->dir.z * ray->dir.z);
	e.b = (ray->dir.x * p.x + ray->dir.z * p.z) * 2.0;
	e.c = (p.x * p.x + p.z * p.z) - s->radius * s->radius;
	vec_unrotate(&ray->dir, s->rot);
	return (solve_quadratic(e, t));
}
