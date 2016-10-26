/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/23 18:14:32 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	inter_cylinders(t_ray *ray, t_obj *s, double *t)
{
	t_equation		e;

	e.a = (1 - s->rot.x) * (ray->dir.x * ray->dir.x) + (1 - s->rot.y) * (ray->dir.y * ray->dir.y)
		+ (1 - s->rot.z) * (ray->dir.z * ray->dir.z);

	e.b = (1 - s->rot.x) * (ray->dir.x * (ray->origin.x - s->pos.x))
		+ (1 - s->rot.y) * (ray->dir.y * (ray->origin.y - s->pos.y))
		+ (1 - s->rot.z) * (ray->dir.z * (ray->origin.z - s->pos.z));
	e.b *= 2.0;

	e.c = (1 - s->rot.y) * ((ray->origin.y - s->pos.y) * (ray->origin.y - s->pos.y))
		+ (1 - s->rot.x) * ((ray->origin.x - s->pos.x) * (ray->origin.x - s->pos.x))
		+ (1 - s->rot.z) * ((ray->origin.z - s->pos.z) * (ray->origin.z - s->pos.z));
	e.c -= (s->radius * s->radius);

	return(solve_quadratic(e, t));
}
