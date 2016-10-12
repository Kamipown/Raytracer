/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_planes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:35:39 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/08 22:11:15 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	mul_d_to_vec(double d, t_vec3 *v)
{
	t_vec3 ret;

	ret.x = v->x * d;
	ret.y = v->y * d;
	ret.z = v->z * d;
	return (ret);
}

void	inter_planes(t_ray *ray, t_obj *p, double *z)
{
	t_vec3	N;
	double	m;
	t_vec3	L;
	double	d;
	double	t;
	t_vec3	ret;
	t_vec3	tmp;

	N = (t_vec3){p->rot.x, p->rot.y, p->rot.z};
	vec_normalize(&N);
	m = vec_mul_to_d(&N, &ray->dir);
	if (fabs(m) < 0.000001)
		return ;
	L = vec_sub(&ray->origin, &p->pos);
	d = vec_mul_to_d(&N, &L);
	t = -d / m;
	if (t <= 0)
		return ;
	tmp = mul_d_to_vec(t, &ray->dir);
	ret = vec_add(&ray->origin, &tmp);
	*z = ret.z;
}
