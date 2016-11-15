/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_spheres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:42:48 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/14 23:28:03 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool			inter_spheres(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_vec3		tmp_dir;
	t_vec3		p;

	tmp_dir = (t_vec3){ray->dir.x, ray->dir.y, ray->dir.z};
	p = vec_sub(ray->origin, s->pos);
	vec_rotate(&p, s->rot);
	vec_rotate(&tmp_dir, s->rot);
	e.a = tmp_dir.x * tmp_dir.x
		+ tmp_dir.y * tmp_dir.y
		+ tmp_dir.z * tmp_dir.z;
	e.b = tmp_dir.x * p.x
		+ tmp_dir.y * p.y
		+ tmp_dir.z * p.z;
	e.b *= 2.0;
	e.c = p.x * p.x
		+ p.y * p.y
		+ p.z * p.z;
	e.c -= (s->radius * s->radius);
	return (solve_quadratic(e, t));
}
