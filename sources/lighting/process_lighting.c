/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/27 22:22:10 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			add_lambert_light_contribution(t_env *e, t_obj *obj, t_light *l, t_vec3 *new_start, t_color *c, t_vec3 *n, double coef)
{
	t_vec3			dist;
	t_intersection	*inter;
	t_vec3 			impact;
	double			t;
	double			lambert;

	dist = vec_sub(l->pos, *new_start);
	if (vec_mul_to_d(*n, dist) <= 0.00000)
		return ;
	t = sqrtf(vec_mul_to_d(dist, dist));
	if (t <= 0.00000)
		return ;
	e->scene.light_ray.origin = *new_start;
	e->scene.light_ray.dir = (t_vec3){dist.x, dist.y, dist.z};
	vec_normalize(&e->scene.light_ray.dir);
	inter = throw_ray(e, &e->scene.light_ray, 0);
	if (inter->obj)
	{
		impact = vec_add(e->scene.light_ray.origin, vec_mul_d(e->scene.light_ray.dir, inter->t));
		if (calc_dist(new_start, &impact) < calc_dist(new_start, &l->pos))
		{
			free(inter);
			return ;
		}
	}
	lambert = vec_mul_to_d(e->scene.light_ray.dir, *n) * coef;
	c->r += lambert * l->color.r * obj->color.r;
	c->g += lambert * l->color.g * obj->color.g;
	c->b += lambert * l->color.b * obj->color.b;
	free(inter);
}

void			add_reflection_contribution(t_obj *obj, t_ray *ray, t_vec3 *n, double *coef)
{
	double	refl;

	*coef *= obj->refl;
	refl = 2.0 * vec_mul_to_d(ray->dir, *n);
	*n = vec_mul_d(*n, refl);
}

void			process_lighting(t_env *e, t_ray *ray, t_intersection *inter, t_color *color)
{
	double			coef;
	int				level;
	t_vec3			new_start;
	t_vec3			n;
	int				i;

	coef = 2.0;
	level = 0;
	while (coef > 0.00000 && level < 10)
	{
		new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
		n = get_normal(&new_start, inter->obj, ray);
		i = 0;
		while (i < e->scene.n_light)
			add_lambert_light_contribution(e, inter->obj, &e->scene.lights[i++], &new_start, color, &n, coef);
		add_reflection_contribution(inter->obj, ray, &n, &coef);
		ray->origin = new_start;
		ray->dir = vec_sub(ray->dir, n);
		inter = throw_ray(e, ray, 0);
		if (!inter->obj)
			break ;
		level++;
	}
	flour_color(color);
}
