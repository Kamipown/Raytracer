/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/23 04:20:41 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_color	get_global_illuminated_color(t_color *c)
{
	t_color	color;

	color.r = c->r * 0.1;
	color.g = c->g * 0.1;
	color.b = c->b * 0.1;
	return (color);
}

t_vec3			get_normal(t_vec3 *pos, t_obj *obj)
{
	t_vec3	normal;

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
		normal = vec_sub(*pos, obj->pos);
		vec_normalize(&normal);
	}
	return (normal);
}

double			calc_dist(t_vec3 *v1, t_vec3 *v2)
{
	return (sqrtf((v1->x - v2->x) * (v1->x - v2->x)
				+ (v1->y - v2->y) * (v1->y - v2->y)
				+ (v1->z - v2->z) * (v1->z - v2->z)));
}

void			add_lambert_light_contribution(t_env *e, t_obj *obj, t_light *l, t_vec3 *new_start, t_color *c, t_vec3 *n, double coef)
{
	t_vec3			dist;
	t_ray			ray;
	t_intersection	*inter;
	double			t;
	double			lambert;

	dist = vec_sub(l->pos, *new_start);
	if (vec_mul_to_d(*n, dist) <= 0.00000)
		return ;
	t = sqrtf(vec_mul_to_d(dist, dist));
	if (t <= 0.00000)
		return ;
	ray.origin = *new_start;
	ray.dir = (t_vec3){dist.x, dist.y, dist.z};
	vec_normalize(&ray.dir);
	inter = throw_ray(e, &ray, 0);
	if (inter->obj)
	{
		t_vec3 impact;

		impact = vec_add(ray.origin, vec_mul_d(ray.dir, inter->t));
		if (calc_dist(new_start, &impact) < calc_dist(new_start, &l->pos))
		{
			free(inter);
			return ;
		}
	}
	lambert = vec_mul_to_d(ray.dir, *n) * coef;
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

void			flour_color(t_color *color)
{
	color->r = (color->r * 255 > 255) ? 255 : color->r * 255;
	color->g = (color->g * 255 > 255) ? 255 : color->g * 255;
	color->b = (color->b * 255 > 255) ? 255 : color->b * 255;
}

t_color			process_lighting(t_env *e, t_ray *ray, t_intersection *inter)
{
	t_color			color;
	double			coef;
	int				level;
	t_vec3			new_start;
	t_vec3			n;
	int				i;

	color = get_global_illuminated_color(&inter->obj->color);
	coef = 2.0;
	level = 0;
	while (coef > 0.00000 && level < 10)
	{
		new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
		n = get_normal(&new_start, inter->obj);
		i = 0;
		while (i < e->scene->n_light)
			add_lambert_light_contribution(e, inter->obj, &e->scene->lights[i++], &new_start, &color, &n, coef);
		add_reflection_contribution(inter->obj, ray, &n, &coef);
		ray->origin = new_start;
		ray->dir = vec_sub(ray->dir, n);
		// if (inter)
		// 	free(inter);
		inter = throw_ray(e, ray, 0);
		if (!inter->obj)
			break ;
		level++;
	}
	flour_color(&color);
	return (color);
}
