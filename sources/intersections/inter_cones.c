/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/11/14 03:07:23 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	inter_cones(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_vec3		p;
	double		rayon;

	p = vec_sub(ray->origin, s->pos);
	vec_unrotate(&p, s->rot);
	vec_unrotate(&ray->dir, s->rot);
	rayon = sin(DEG_TO_RAD(s->radius)) * sin(DEG_TO_RAD(s->radius));
	e.a = ray->dir.x * ray->dir.x
		- ray->dir.y * ray->dir.y * rayon
		+ ray->dir.z * ray->dir.z;
	e.b = (ray->dir.x * p.x - ray->dir.y * p.y * rayon + ray->dir.z * p.z)
		* 2.0;
	e.c = p.x * p.x - p.y * p.y * rayon + p.z * p.z;
	vec_rotate(&ray->dir, s->rot);
	return (solve_quadratic(e, t));
}
