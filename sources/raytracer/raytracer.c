/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 16:06:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_color	color_median(t_color c[9])
{
	t_color	ret;

	ret.r = (c[0].r + c[1].r + c[2].r + c[3].r + c[4].r + c[5].r + c[6].r
			+ c[7].r + c[8].r) / 9;
	ret.g = (c[0].g + c[1].g + c[2].g + c[3].g + c[4].g + c[5].g + c[6].g
			+ c[7].g + c[8].g) / 9;
	ret.b = (c[0].b + c[1].b + c[2].b + c[3].b + c[4].b + c[5].b + c[6].b
			+ c[7].b + c[8].b) / 9;
	return (ret);
}

static void	raytrace_pixel_ssaa3(t_env *e, int x, int y)
{
	t_ray			*ray;
	t_intersection	*inter;
	t_color			color[9];
	int				tx;
	int				ty;

	ty = 0;
	while (ty < 3)
	{
		tx = 0;
		while (tx < 3)
		{
			ray = create_ray(e->scene->cam, (t_vec3)
			{
				(x - (e->scene->size.w / 2)) + (tx * 0.333),
				(y - (e->scene->size.h / 2)) + (ty * 0.333),
				0
			});
			inter = throw_ray(e, ray, 0);
			if (inter->obj)
				color[tx + 3 * ty] = process_lighting(e, ray, inter);
			else
				color[tx + 3 * ty] = (t_color){0, 0, 0};
			free(ray);
			//free(inter);
			++tx;
		}
		++ty;
	}
	draw_pixel(e, (t_pixel){x, y, color_median(color)});
}

static void	raytrace_pixel(t_env *e, int x, int y)
{
	t_ray			*ray;
	t_intersection	*inter;
	t_color			color;

	//if (x != 50 || y != 50) return ;
	ray = create_ray(
		e->scene->cam,
		(t_vec3){x - (e->scene->size.w / 2), y - (e->scene->size.h / 2), 0}
	);
	inter = throw_ray(e, ray, 0);
	if (inter->obj)
	{
		color = process_lighting(e, ray, inter);
		draw_pixel(e, (t_pixel){x, y, color});
	}
	free(ray);
	// if (inter)
	// 	free(inter);
}

void		raytrace(t_env *e)
{
	int				x;
	int				y;
	t_bool			ssaa;

	ssaa = TRUE;
	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			if (ssaa)
				raytrace_pixel_ssaa3(e, x, y);
			else
				raytrace_pixel(e, x, y);
			++x;
		}
		++y;
	}
}
