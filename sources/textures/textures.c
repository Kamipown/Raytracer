/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 03:28:06 by gromon            #+#    #+#             */
/*   Updated: 2016/11/08 03:20:47 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		perlin_noise(t_intersection *inter, t_color *c, t_ray *ray)
{
	double	noise_coef;
	int		level;
	t_vec3	vec;
	t_vec3	pos;

	noise_coef = 0;
	pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	vec.x = pos.x * 0.5;
	vec.y = pos.y * 0.5;
	vec.z = pos.z * 0.5;
	level = 1;
	while (++level < 10)
	{
		noise_coef += (1.0 / level) * fabs(noise3(vec));
	}
	noise_coef = 0.8 * cos((pos.x + pos.y + pos.z) * 0.05 + noise_coef) + 0.9;
	c->r = inter->obj->color.r * noise_coef;
	c->g = inter->obj->color.g * noise_coef;
	c->b = inter->obj->color.b * noise_coef;
}

void		perlin_lines(t_intersection *inter, t_color *c, t_ray *ray)
{
	t_vec3	pos;

	pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	if (((int)(pos.x + 1000000) / 10 +
	(int)(pos.y * 2 + 1000000) / 10) % 2 == 0)
	{
		c->r = inter->obj->color.r / 2;
		c->g = inter->obj->color.g / 2;
		c->b = inter->obj->color.b / 2;
	}
	else
	{
		c->r = inter->obj->color.r;
		c->g = inter->obj->color.g;
		c->b = inter->obj->color.b;
	}
}

void		perlin_marble(t_intersection *inter, t_color *c, t_ray *ray)
{
	double	noise_coef;
	int		level;
	t_vec3	vec;
	t_vec3	pos;

	noise_coef = 0;
	pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	vec.x = pos.x * 5;
	vec.y = pos.y * 5;
	vec.z = pos.z * 5;
	level = 1;
	while (++level < 10)
	{
		noise_coef += (1.0 / level) * fabs(noise3(vec));
	}
	noise_coef = 0.5 * sin((pos.x + pos.y) * 0.05 + noise_coef) + 0.5;
	c->r = inter->obj->color.r * noise_coef + (1.0 - noise_coef);
	c->g = inter->obj->color.g * noise_coef + (1.0 - noise_coef);
	c->b = inter->obj->color.b * noise_coef + (1.0 - noise_coef);
}

void		earth_texture(t_intersection *inter, t_color *c,
							t_ray *ray, t_obj *obj)
{
	double	u;
	double	v;
	t_vec3	n;
	t_vec3	pos;
	Uint32	*pixel;

	pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	n = get_normal(&pos, obj);
	u = ((0.5 + atan(n.x / -n.z) / (2 * M_PI)) * obj->bmp->w);
	v = ((0.5 - asin(n.y) / M_PI) * obj->bmp->h);
	u = fmod(u, obj->bmp->w - 1);
	v = obj->bmp->h - fmod(v, obj->bmp->h - 1);
	pixel = (Uint32 *)((char *)obj->bmp->pixels + (Uint32)v *
	(Uint32)obj->bmp->pitch + (Uint32)u * obj->bmp->format->BytesPerPixel);
	*c = uint32_to_color(*pixel, obj->bmp);
}

void		select_textures(t_intersection *inter, t_color *c,
							t_env *e, t_obj *obj)
{
	if (inter->obj->textures == 0)
		return ;
	else if (inter->obj->textures == 1)
		perlin_noise(inter, c, &e->scene.ray);
	else if (inter->obj->textures == 2)
		perlin_lines(inter, c, &e->scene.ray);
	else if (inter->obj->textures == 3)
		perlin_marble(inter, c, &e->scene.ray);
	else if (inter->obj->textures == 4)
	{
		obj->bmp = e->textures.map;
		earth_texture(inter, c, &e->scene.ray, obj);
	}
}
