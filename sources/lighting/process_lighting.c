/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 03:30:26 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/31 22:16:17 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			add_lambert_light_contribution(t_env *e, t_obj *obj, t_light *l, t_vec3 *new_start, t_color *c, t_vec3 *n, double coef)
{
	t_vec3			dist;
	t_intersection	inter;
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
	if (inter.obj)
	{
		if (inter.obj->refr == 1.0)
		{

			return ;
		}

		impact = vec_add(e->scene.light_ray.origin, vec_mul_d(e->scene.light_ray.dir, inter.t));
		if (calc_dist(new_start, &impact) < calc_dist(new_start, &l->pos))
			return ;
	}
	lambert = vec_mul_to_d(e->scene.light_ray.dir, *n) * coef;
	c->r += lambert * l->color.r * obj->color.r;
	c->g += lambert * l->color.g * obj->color.g;
	c->b += lambert * l->color.b * obj->color.b;
}

void			add_reflection_contribution(t_obj *obj, t_ray *ray, t_vec3 *n, double *coef)
{
	double	refl;

	*coef *= obj->refl;
	refl = 2.0 * vec_mul_to_d(ray->dir, *n);
	*n = vec_mul_d(*n, refl);
}

t_bool			add_refraction_contribution(t_ray *ray, t_vec3 n, double change/*(n1 / n2)*/, t_vec3 *result)
{
	double	cos_i;
	double	cos_t;
	double	sin_t;
	double 	n1;
	double 	n2;
	// t_vec3 	new_ray;
	//
	//
	// new_ray = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));


	cos_i = -vec_mul_to_d(ray->dir, n);
	if (cos_i > 0.0f)
	{
		n1 = change;
		n2 = 1.0f;
		n = (t_vec3){-n.x, -n.y, -n.z};
	}
	else
	{
		n1 = 1.0f;
		n2 = change;
		//n2 = obj[ok].mat.refract;
		cos_i = -cos_i;
	}
	change = n1 / n2;
	sin_t = change * change * (1.0 - (cos_i * cos_i));
	if (sin_t > 1.0)
		return FALSE;
	cos_t = sqrt(1.0 - sin_t);
	*result = vec_add(vec_mul_d(ray->dir, change), vec_mul_d(n, change * cos_i - cos_t));
	return TRUE;
	//*n = vec_mul_d(*n, refl);
}

/*static void launch_reflection_ray(t_env *e, t_intersection *inter, t_ray *ray, t_vec3 *n, int level)
{
	if (level >= 10)
		return ;
	throw_ray(e, ray, 0);
	add_reflection_contribution(inter->obj, ray, &n, &coef);
	intersect_objects(e, ray, inter, 0);
	process_lighting(t_env *e, t_ray *ray, t_intersection *inter);
}*/


void			process_lighting(t_env *e, t_ray *ray, t_intersection inter, t_color *color)
{
	double			coef;
	int				level;
	t_vec3			new_start;
	t_vec3			n;
	int				i;
	t_obj			*old;

	coef = 2.0;
	level = 0;
	old = 0;
	while (coef > 0.00000 && level < 10)
	{
		new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter.t));
		n = get_normal(&new_start, inter.obj, ray);
		bump_mapping(&inter, ray, &n);
		i = 0;
		while (i < e->scene.n_light)
			add_lambert_light_contribution(e, inter.obj, &e->scene.lights[i++], &new_start, color, &n, coef);
		if (inter.obj->refr == 1.0)
		{
			if (!old)
				old = inter.obj;
			new_start = vec_add(ray->origin, vec_mul_d(ray->dir, inter.t + EPSILON));
		}
		else
		{
			ray->dir = vec_sub(ray->dir, n);
		}
		if (old && inter.obj->refr != 1.0)
		{
			*color = old->color;
			old = 0;
			printf("... %f %f %f\n", color->r, color->g, color->b);
		}
		add_reflection_contribution(inter.obj, ray, &n, &coef);
		ray->origin = new_start;
		inter = throw_ray(e, ray, 0);
		if (!inter.obj)
			break ;
		level++;
	}
}
