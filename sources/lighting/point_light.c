/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 03:42:29 by gromon            #+#    #+#             */
/*   Updated: 2016/11/15 02:39:07 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	lambert_point(t_env *e, t_lambert *lamb)
{
	lamb->dist = vec_sub(lamb->l->pos, *lamb->new_start);
	if (vec_mul_to_d(*lamb->n, lamb->dist) <= 0.00000)
		return ;
	lamb->t = sqrtf(vec_mul_to_d(lamb->dist, lamb->dist));
	if (lamb->t <= 0.00000)
		return ;
	e->scene.light_ray.origin = *lamb->new_start;
	e->scene.light_ray.dir = vec_mul_d(lamb->dist, 1.0 / lamb->t);
	lamb->inter = throw_ray(e, &e->scene.light_ray);
	if (lamb->inter.obj)
	{
		lamb->impact = vec_add(e->scene.light_ray.origin,
			vec_mul_d(e->scene.light_ray.dir, lamb->inter.t));
		if (calc_dist(lamb->new_start, &lamb->impact) <
			calc_dist(lamb->new_start, &lamb->l->pos))
			return ;
	}
	final_pixel_color(e, lamb);
}
