/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/15 02:20:06 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_color		get_pixel_color(t_intersection *inter, t_env *e)
{
	t_color			color;

	color = (t_color){0, 0, 0};
	if (inter->obj)
	{
		color = get_global_illuminated_color(&inter->obj->color,
			&e->scene.ambient);
		select_textures(inter, &color, e, inter->obj);
		process_lighting(e, &e->scene.ray, *inter, &color);
		flour_color(&color);
	}
	return (color);
}

static t_color		color_median(t_color c[9])
{
	t_color			ret;

	ret.r = (c[0].r + c[1].r + c[2].r + c[3].r + c[4].r + c[5].r + c[6].r
			+ c[7].r + c[8].r) / 9;
	ret.g = (c[0].g + c[1].g + c[2].g + c[3].g + c[4].g + c[5].g + c[6].g
			+ c[7].g + c[8].g) / 9;
	ret.b = (c[0].b + c[1].b + c[2].b + c[3].b + c[4].b + c[5].b + c[6].b
			+ c[7].b + c[8].b) / 9;
	return (ret);
}

static void			raytrace_pixel_ssaa3(t_env *e, int x, int y)
{
	t_intersection	inter;
	t_color			color[9];
	int				tx;
	int				ty;

	ty = 0;
	while (ty < 3)
	{
		tx = 0;
		while (tx < 3)
		{
			create_ray(&e->scene, (t_vec3)
			{
				(x - (e->scene.current_mode->w / 2)) + (tx * 0.333),
				(y - (e->scene.current_mode->h / 2)) + (ty * 0.333),
				0
			});
			inter = throw_ray(e, &e->scene.ray);
			color[tx + 3 * ty] = get_pixel_color(&inter, e);
			++tx;
		}
		++ty;
	}
	draw_pixel(e, (t_pixel){x, y, color_median(color)});
}

static void			raytrace_pixel(t_env *e, int x, int y)
{
	t_intersection	inter;
	t_color			color;

	create_ray(&e->scene, (t_vec3)
	{
		x - (e->scene.current_mode->w / 2),
		y - (e->scene.current_mode->h / 2),
		0
	});
	inter = throw_ray(e, &e->scene.ray);
	color = get_pixel_color(&inter, e);
	draw_pixel(e, (t_pixel){x, y, color});
}



static void			drawloader(t_env *e, int prc)
{
	SDL_SetRenderDrawColor(e->renderer_sub,
		124,
		252,
		0,
		255);
	SDL_RenderDrawRect(e->renderer_sub, &((SDL_Rect){prc * 3, 0, 3, 5}));
	SDL_RenderPresent(e->renderer_sub);
}

void				raytrace(t_env *e)
{
	int		x;
	int		y;
	int		i;
	int		old;
	int		tmp;
	int		pc;

	pc = e->scene.current_mode->h * e->scene.current_mode->w;
	i = 0;
	old = 0;
	tmp = 0;
	y = 0;	
	while (y < e->scene.current_mode->h)
	{
		x = 0;
		while (x < e->scene.current_mode->w)
		{
			if (e->scene.ssaa)
				raytrace_pixel_ssaa3(e, x, y);
			else
				raytrace_pixel(e, x, y);
			old = tmp;
			tmp = (100 * i / pc);
			if (old != tmp)
				drawloader(e, tmp);
			i++;
			++x;
		}
		++y;
	}
}
