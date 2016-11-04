/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 03:50:41 by gromon            #+#    #+#             */
/*   Updated: 2016/11/04 00:11:46 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_bool			solve_quadratic(t_equation e, double *t)
{
	t_bool		ret;

	e.delta = (e.b * e.b - (4 * e.a * e.c));
	if (e.delta < 0.0)
		return (FALSE);
	e.z1 = (-e.b + sqrt(e.delta)) / (2.0 * e.a);
	e.z2 = (-e.b - sqrt(e.delta)) / (2.0 * e.a);
	ret = FALSE;
	if (e.z1 > 0.1)
	{
		*t = e.z1;
		ret = TRUE;
	}
	if (e.z2 > 0.1 && e.z2 < e.z1)
	{
		*t = e.z2;
		ret = TRUE;
	}
	return (ret);
}

double			calc_dist(t_vec3 *v1, t_vec3 *v2)
{
	return (sqrtf((v1->x - v2->x) * (v1->x - v2->x)
				+ (v1->y - v2->y) * (v1->y - v2->y)
				+ (v1->z - v2->z) * (v1->z - v2->z)));
}

t_vec3			get_normal(t_vec3 *pos, t_obj *obj, t_ray *ray)
{
	t_vec3		normal;

	normal = (t_vec3){0, 0, 0};
	if (obj->type == SPHERE)
	{
		normal = vec_sub(*pos, obj->pos);
		vec_normalize(&normal);
	}
	else if (obj->type == PLANE)
	{
		normal = (t_vec3){obj->rot.x, obj->rot.y, obj->rot.z};
	}
	else if (obj->type == CYLINDER)
	{
		/*if (sqrt((obj->rot.x) * ((obj->pos.x - pos->x) * (obj->pos.x - pos->x))
			+ (obj->rot.y) * ((obj->pos.y - pos->y) * (obj->pos.y - pos->y))
			+ (obj->rot.z) * ((obj->pos.z - pos->z) * (obj->pos.z - pos->z))) == 50)
		{
			normal = (t_vec3){0, -1, 0};
		}
		else
		{
			normal = vec_sub(*pos, obj->pos);
			normal.y = 0;
		}
		vec_normalize(&normal);*/
	}
	else if (obj->type == CONE)
	{
		normal = (t_vec3){ray->dir.x, 0, (1 - tan(obj->radius))
					* tan(obj->radius)};
		vec_normalize(&normal);
	}
	return (normal);
}

t_color			uint32_to_color(Uint32 color, SDL_Surface *bmp)
{
	t_color		c;
	Uint8		truecolor[3];

	SDL_GetRGB(color, bmp->format, &truecolor[0], &truecolor[1], &truecolor[2]);
	c = (t_color){truecolor[0] / 255.0,
	truecolor[1] / 255.0, truecolor[2] / 255.0};
	return (c);
}
