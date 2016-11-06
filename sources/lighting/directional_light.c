/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 03:42:25 by gromon            #+#    #+#             */
/*   Updated: 2016/11/06 22:59:26 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	lambert_directional(t_env *e, t_lambert *lamb)
{
	e->scene.light_ray.origin = *lamb->new_start;
	e->scene.light_ray.dir = (t_vec3){-lamb->l->dir.x, -lamb->l->dir.y, -lamb->l->dir.z};
	lamb->inter = throw_ray(e, &e->scene.light_ray);
	if (lamb->inter->obj)
	{
		return ;
	}
	lamb->lambert = vec_mul_to_d(e->scene.light_ray.dir, *lamb->n) * lamb->coef;
	lamb->c->r += lamb->lambert * lamb->l->color.r * lamb->obj->color.r;
	lamb->c->g += lamb->lambert * lamb->l->color.g * lamb->obj->color.g;
	lamb->c->b += lamb->lambert * lamb->l->color.b * lamb->obj->color.b;
	free(lamb->inter);
}
