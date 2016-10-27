/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 03:28:06 by gromon            #+#    #+#             */
/*   Updated: 2016/10/28 00:11:27 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	perlin_lines(t_intersection *inter, t_color *c, t_ray *ray)
{
	double	noise_coef;
	int		level;
	t_vec3 	vec;
	t_vec3 	pos;
	
	noise_coef = 0;
	pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	vec.x = pos.x * 0.5;
	vec.y = pos.y * 0.5;
	vec.z = pos.z * 0.5;
	level = 1;
	while (++level < 10)
	{
		noise_coef += (1.0 / level) * fabs(noise3(&vec));
	}
	noise_coef = 0.8 * cos((pos.x + pos.y + pos.z) * 0.05 + noise_coef) + 0.9;
	c->r = inter->obj->color.r  * noise_coef;
	c->g = inter->obj->color.g  * noise_coef;
	c->b = inter->obj->color.b  * noise_coef;
}

void	perlin_chess(t_intersection *inter, t_color *c, t_ray *ray)
{
	t_vec3 	pos;

	pos = vec_add(ray->origin, vec_mul_d(ray->dir, inter->t));
	if (((int)(pos.x + 99999) / 2 + (int)(pos.y * 2 + 99999) / 2) % 2 == 0)
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

void			select_textures(t_intersection *inter, t_color *c, t_ray *ray)
{
	if (inter->obj->textures == 0)
		return;
	else if (inter->obj->textures == 1)
		perlin_lines(inter, c, ray);
	else if (inter->obj->textures == 2)
		perlin_chess(inter, c, ray);
}
