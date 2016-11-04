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

t_bool		get_quadratic(t_equation *e, double *t)
{
	t_bool	ret;

	e->delta = (e->b * e->b - (4 * e->a * e->c));
	if (e->delta < 0.0)
		return (FALSE);
	e->z1 = (-e->b + sqrt(e->delta)) / (2.0 * e->a);
	e->z2 = (-e->b - sqrt(e->delta)) / (2.0 * e->a);
	ret = FALSE;
	if (e->z1 > 0.1)
	{
		*t = e->z1;
		ret = TRUE;
	}
	if (e->z2 > 0.1 && e->z2 < e->z1)
	{
		*t = e->z2;
		ret = TRUE;
	}
	return (ret);
}


t_bool	inter_cylinders(t_ray *ray, t_obj *s, double *t)
{
	t_equation	e;
	t_bool		def_res;
	t_vec3		pos;
	double		th;
	double		y0;
	double		y1;

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
	def_res = get_quadratic(&e, t);
	if (def_res == TRUE)
		return TRUE;
	pos = vec_add(ray->origin, vec_mul_d(ray->dir, *t));
	if (sqrt((s->rot.x) * ((s->pos.x - pos.x) * (s->pos.x - pos.x))
		+ (s->rot.y) * ((s->pos.y - pos.y) * (s->pos.y - pos.y))
		+ (s->rot.z) * ((s->pos.z - pos.z) * (s->pos.z - pos.z))) < size)
		return TRUE;
	if (e.z1 > e.z2)
	{
		*t = e.z2;
		e.z2 = e.z1;
		e.z1 = *t;
	}
	y0 = ray->origin.y * (ray->dir.y + e.z1);
	y1 = ray->origin.y * (ray->dir.y + e.z2);
	th = e.z1 + (e.z2 -e.z1) * (y0+1) / (y0-y1);
	if (((e.z1 < -1 && e.z2 > -1) || (e.z1 > 1 && e.z2 < 1)) && th > 0)
	{
		printf_vec3("pos", pos);
		printf("%f> %f %f\n", th, y0, y1);
		*t = th;
		return TRUE;
	}
	*t = 0.00001;
	return FALSE;
}
