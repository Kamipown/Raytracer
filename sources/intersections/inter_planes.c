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

	n = (t_vec3){p->rot.x, p->rot.y, p->rot.z};
	vec_normalize(&n);
	m = vec_mul_to_d(n, ray->dir);
	if (fabs(m) < 0.000001)
		return (FALSE);
	l = vec_sub(ray->origin, p->pos);
	d = vec_mul_to_d(n, l);
	*t = -d / m;
	if (*t <= 0.000001)
		return (FALSE);
	return (TRUE);
}
