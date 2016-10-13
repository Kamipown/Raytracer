/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/13 21:51:03 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		raytrace(t_env *e)
{
	int				x;
	int				y;
	t_ray			*ray;
	t_intersection	*inter;

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
				process_lighting(e, ray, inter);
				//draw_pixel(e, (t_pixel){x, y, inter->obj->color});
			}
			free(inter);
			free(ray);
			++x;
		}
		++y;
	}
}
