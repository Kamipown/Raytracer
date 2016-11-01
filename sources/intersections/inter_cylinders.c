/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/28 00:58:27 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void printf_vec3(char *name, t_vec3 v) {
	printf("(%s){%f, %f, %f}\n",name, v.x,v.y,v.z);
}

t_bool	inter_cylinders(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_bool		def_res;
	t_vec3		pos;

	double size = 100;
	e.a = (1 - s->rot.x) * (ray->dir.x * ray->dir.x) + (1 - s->rot.y)
			* (ray->dir.y * ray->dir.y)
			+ (1 - s->rot.z) * (ray->dir.z * ray->dir.z);
	e.b = (1 - s->rot.x) * (ray->dir.x * (ray->origin.x - s->pos.x))
		+ (1 - s->rot.y) * (ray->dir.y * (ray->origin.y - s->pos.y))
		+ (1 - s->rot.z) * (ray->dir.z * (ray->origin.z - s->pos.z));
	e.b *= 2.0;
	e.c = (1 - s->rot.y) * ((ray->origin.y - s->pos.y)
			* (ray->origin.y - s->pos.y))
			+ (1 - s->rot.x) * ((ray->origin.x - s->pos.x)
			* (ray->origin.x - s->pos.x))
			+ (1 - s->rot.z) * ((ray->origin.z - s->pos.z)
			* (ray->origin.z - s->pos.z));
	e.c -= (s->radius * s->radius);
	def_res = solve_quadratic(e, t);
	if (def_res == FALSE)
		return FALSE;
	pos = vec_add(ray->origin, vec_mul_d(ray->dir, *t));
	//printf("*> %f %f %f\n", vec_mul_d(ray->dir, *t).x,vec_mul_d(ray->dir, *t).y,vec_mul_d(ray->dir, *t).z);

	if (sqrt((s->rot.x) * ((s->pos.x - pos.x) * (s->pos.x - pos.x))
		+ (s->rot.y) * ((s->pos.y - pos.y) * (s->pos.y - pos.y))
		+ (s->rot.z) * ((s->pos.z - pos.z) * (s->pos.z - pos.z))) < size)
		return TRUE;
	*t = 0.00001;
	return FALSE;
}
