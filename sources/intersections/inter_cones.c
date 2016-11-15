/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by vmontagn          #+#    #+#             */
/*   Updated: 2016/11/14 23:24:44 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool	inter_cones(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_vec3		p;
	double		rayon;
	t_vec3		tmp_dir;

	tmp_dir = (t_vec3){ray->dir.x, ray->dir.y, ray->dir.z};
	p = vec_sub(ray->origin, s->pos);
	vec_rotate(&p, s->rot);
	vec_rotate(&tmp_dir, s->rot);
	rayon = sin(deg_to_rad(s->radius)) * sin(deg_to_rad(s->radius));
	e.a = tmp_dir.x * tmp_dir.x
		- tmp_dir.y * tmp_dir.y * rayon
		+ tmp_dir.z * tmp_dir.z;
	e.b = (tmp_dir.x * p.x - tmp_dir.y * p.y * rayon + tmp_dir.z * p.z)
		* 2.0;
	e.c = p.x * p.x - p.y * p.y * rayon + p.z * p.z;
	return (solve_quadratic(e, t));
}
