/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 03:50:47 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/15 03:50:48 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		get_pixel_color(t_intersection *inter, t_env *e)
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

t_color		color_median(t_color c[9])
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
