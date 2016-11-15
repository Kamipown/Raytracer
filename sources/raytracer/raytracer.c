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

static void			draw_loader(t_env *e, int prc)
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
	t_rtc	rtc;

	rtc.pc = e->scene.current_mode->h * e->scene.current_mode->w;
	rtc.i = 0;
	rtc.old = 0;
	rtc.tmp = 0;
	rtc.y = 0;
	while (rtc.y < e->scene.current_mode->h)
	{
		rtc.x = 0;
		while (rtc.x < e->scene.current_mode->w)
		{
			if (e->scene.ssaa)
				raytrace_pixel_ssaa3(e, rtc.x, rtc.y);
			else
				raytrace_pixel(e, rtc.x, rtc.y);
			rtc.old = rtc.tmp;
			rtc.tmp = (100 * rtc.i / rtc.pc);
			if (rtc.old != rtc.tmp)
				draw_loader(e, rtc.tmp);
			rtc.i++;
			++rtc.x;
		}
		++rtc.y;
	}
}
