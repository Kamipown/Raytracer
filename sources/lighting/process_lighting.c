/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/06 22:01:32 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				add_lambert_light_contribution(t_env *e, t_lambert *lamb)
{
	if (lamb->l->type == POINT_LIGHT)
		lambert_point(e, lamb);
	else if (lamb->l->type == DIRECTIONAL_LIGHT)
		lambert_directional(e, lamb);
	else if (lamb->l->type == SPOT_LIGHT)
		lambert_spot(e, lamb);
}

void				add_reflection_contribution(t_obj *obj, t_ray *ray,
						t_vec3 *n, double *coef)
{
	double			refl;

	*coef *= obj->refl;
	refl = 2.0 * vec_mul_to_d(ray->dir, *n);
	*n = vec_mul_d(*n, refl);
}

void				process_lighting(t_env *e, t_ray *ray,
						t_intersection *inter, t_color *color)
{
	double			coef;
	int				level;
	t_vec3			new_start;
	t_lambert		lamb;
	t_vec3			n;
	int				i;

	coef = 2.0;
	level = 0;
	while (coef > 0.00000 && ++level < 10)
	{
		new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
		n = get_normal(&new_start, inter->obj, ray);
		bump_mapping(inter, ray, &n);
		i = 0;
		while (i < e->scene.n_light)
		{
			lamb = (t_lambert){inter->obj, &e->scene.lights[i++], &new_start,
					&n, (t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}, color,
					0, coef, inter->t, 0};
			add_lambert_light_contribution(e, &lamb);
		}
		add_reflection_contribution(inter->obj, ray, &n, &coef);
		ray->origin = new_start;
		ray->dir = vec_sub(ray->dir, n);
		inter = throw_ray(e, ray);
		if (!inter->obj)
			break ;
	}
	flour_color(color);
}
