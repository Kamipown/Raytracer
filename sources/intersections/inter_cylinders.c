/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/14 23:34:13 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool			inter_cylinders(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_vec3		p;
	t_vec3		tmp_dir;

	tmp_dir = (t_vec3){ray->dir.x, ray->dir.y, ray->dir.z};
	p = vec_sub(ray->origin, s->pos);
	vec_rotate(&p, s->rot);
	vec_rotate(&tmp_dir, s->rot);
	e.a = (tmp_dir.x * tmp_dir.x) + (tmp_dir.z * tmp_dir.z);
	e.b = (tmp_dir.x * p.x + tmp_dir.z * p.z) * 2.0;
	e.c = (p.x * p.x + p.z * p.z) - s->radius * s->radius;
	return (solve_quadratic(e, t));
}
