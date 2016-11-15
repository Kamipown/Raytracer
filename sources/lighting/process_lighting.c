/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/15 02:40:02 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					final_pixel_color(t_env *e, t_lambert *lamb)
{
	lamb->lambert = vec_mul_to_d(e->scene.light_ray.dir, *lamb->n) * lamb->coef;
	lamb->c->r += lamb->lambert * lamb->l->color.r
		* lamb->obj->color.r * lamb->l->intensity;
	lamb->c->g += lamb->lambert * lamb->l->color.g
		* lamb->obj->color.g * lamb->l->intensity;
	lamb->c->b += lamb->lambert * lamb->l->color.b
		* lamb->obj->color.b * lamb->l->intensity;
	get_brightness(e, lamb);
	select_effects(e, lamb->c);
}

static void				add_lambert_light_contribution(t_env *e,
							t_lambert *lamb)
{
	if (lamb->l->type == POINT_LIGHT)
		lambert_point(e, lamb);
	else if (lamb->l->type == DIRECTIONAL_LIGHT)
		lambert_directional(e, lamb);
	else if (lamb->l->type == SPOT_LIGHT)
		lambert_spot(e, lamb);
}

static void				add_reflection_contribution(t_obj *obj, t_ray *ray,
							t_vec3 *n, double *coef)
{
	double				refl;

	*coef *= obj->refl;
	refl = 2.0 * vec_mul_to_d(ray->dir, *n);
	*n = vec_mul_d(*n, refl);
}

static t_intersection	launch_reflection(t_env *e, t_vec3 *n,
							t_intersection inter, double *coef)
{
	t_vec3				new_start;
	t_ray				*ray;

	ray = &e->scene.ray;
	new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter.t));
	add_reflection_contribution(inter.obj, ray, n, coef);
	ray->origin = new_start;
	ray->dir = vec_sub(ray->dir, *n);
	return (throw_ray(e, ray));
}

void					process_lighting(t_env *e, t_ray *ray,
							t_intersection inter, t_color *color)
{
	double				coef;
	int					c[2];
	t_vec3				new_start;
	t_lambert			lamb;
	t_vec3				n;

	coef = 2.0;
	c[0] = 0;
	while (coef > 0.00000 && c[0]++ < 10)
	{
		new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter.t));
		n = get_normal(&new_start, inter.obj);
		bump_mapping(&inter, ray, &n);
		c[1] = 0;
		while (c[1] < e->scene.n_light)
		{
			lamb = (t_lambert){inter.obj, &e->scene.lights[c[1]++], &new_start,
					&n, (t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}, color,
					inter, coef, inter.t, 0};
			add_lambert_light_contribution(e, &lamb);
		}
		inter = launch_reflection(e, &n, inter, &coef);
		if (!inter.obj)
			break ;
	}
}
