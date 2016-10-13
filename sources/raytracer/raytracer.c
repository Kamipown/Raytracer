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

void		raytrace(t_env *e)
{
	int				x;
	int				y;
	t_ray			*ray;
	t_intersection	*inter;
	t_pixel			pix;

	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			ray = create_ray(e->scene->cam, (t_vec3)
			{
				x - (e->scene->size.w / 2),
				y - (e->scene->size.h / 2),
				0
			});
			inter = throw_ray(e, ray, 0);
			if (inter->obj)
			{
				pix.x = x;
				pix.y = y;
				process_lighting(e, ray, inter, &pix);
				// pix.color.r = inter->obj->color.r * 255.0;
				// pix.color.g = inter->obj->color.g * 255.0;
				// pix.color.b = inter->obj->color.b * 255.0;
				draw_pixel(e, pix);
				free(inter);
			}
			free(ray);
			++x;
		}
		++y;
	}
}
