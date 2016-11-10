/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_planes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:35:39 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/28 00:51:31 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// static void				apply_rotations(t_vec3 *v)
// {
// 	double	t;

// 	t = v->y;
// 	v->y = v->y * cos(deg_to_rad(45)) + v->z
// 					* -(sin(deg_to_rad(45)));
// 	v->z = t * sin(deg_to_rad(45)) + v->z
// 					* cos(deg_to_rad(45));
// }

t_vec3	mul_d_to_vec(double d, t_vec3 v)
{
	t_vec3 ret;

	ret.x = v.x * d;
	ret.y = v.y * d;
	ret.z = v.z * d;
	return (ret);
}

t_bool	inter_planes(t_ray *ray, t_obj *p, double *t)
{
	t_vec3	n;
	double	m;
	t_vec3	l;
	double	d;
	t_vec3	pos;

	n = (t_vec3){p->rot.x, p->rot.y, p->rot.z};
	vec_normalize(&n);
	m = vec_mul_to_d(n, ray->dir);
	if (fabs(m) < 0.000001)
		return (FALSE);
	l = vec_sub(ray->origin, p->pos);
	d = vec_mul_to_d(n, l);
	*t = -d / m;
	pos = vec_add(ray->origin, vec_mul_d(ray->dir, *t));
	if (p->radius != 0 && (fabs(pos.z - p->pos.z) > p->radius
		|| fabs(pos.y - p->pos.y) > p->radius
		|| fabs(pos.x - p->pos.x) > p->radius))
		*t = 0.000001;
	if (*t <= 0.000001)
		return (FALSE);
	return (TRUE);
}
