/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/04 04:12:31 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				add_lambert_light_contribution(t_env *e, t_lambert *lamb)
{
	// if (l->type == POINT_LIGHT)
	// 	;
	// else if (l->type == SPOT_LIGHT)
	// 	;
	// else if (l->type == DIRECTIONAL_LIGHT)
	// 	;
	lamb->dist = vec_sub(lamb->l->pos, *lamb->new_start);
	if (vec_mul_to_d(*lamb->n, lamb->dist) <= 0.00000)
		return ;
	lamb->t = sqrtf(vec_mul_to_d(lamb->dist, lamb->dist));
	if (lamb->t <= 0.00000)
		return ;
	e->scene.light_ray.origin = *lamb->new_start;
	e->scene.light_ray.dir = (t_vec3){lamb->dist.x, lamb->dist.y, lamb->dist.z};
	vec_normalize(&e->scene.light_ray.dir);
	lamb->inter = throw_ray(e, &e->scene.light_ray);
	if (lamb->inter->obj)
	{
		lamb->impact = vec_add(e->scene.light_ray.origin,
		vec_mul_d(e->scene.light_ray.dir, lamb->inter->t));
		if (calc_dist(lamb->new_start, &lamb->impact) < calc_dist(lamb->new_start, &lamb->l->pos))
		{
			free(lamb->inter);
			return ;
		}
	}
	lamb->lambert = vec_mul_to_d(e->scene.light_ray.dir, *lamb->n) * lamb->coef;
	lamb->c->r += lamb->lambert * lamb->l->color.r * lamb->obj->color.r;
	lamb->c->g += lamb->lambert * lamb->l->color.g * lamb->obj->color.g;
	lamb->c->b += lamb->lambert * lamb->l->color.b * lamb->obj->color.b;
	free(lamb->inter);
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
	while (coef > 0.00000 && level < 10)
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
		level++;
	}
	flour_color(color);
}
