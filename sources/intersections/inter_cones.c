/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/10/28 01:03:08 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	inter_cones(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	double		rayon;

	rayon = sin(DEG_TO_RAD(s->radius)) * sin(DEG_TO_RAD(s->radius));
	e.a = ray->dir.x * ray->dir.x
		- (ray->dir.y * ray->dir.y) * rayon
		+ ray->dir.z * ray->dir.z;
	e.b = ray->dir.x * (ray->origin.x - s->pos.x)
		- (ray->dir.y * (ray->origin.y - s->pos.y)) * rayon
		+ ray->dir.z * (ray->origin.z - s->pos.z);
	e.b *= 2.0;
	e.c = (ray->origin.x - s->pos.x) * (ray->origin.x - s->pos.x)
		- ((ray->origin.y - s->pos.y) * (ray->origin.y - s->pos.y)) * rayon
		+ (ray->origin.z - s->pos.z) * (ray->origin.z - s->pos.z);
	return (solve_quadratic(e, t));
}
