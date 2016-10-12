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
			if ((inter = throw_ray(e, ray, 0)))
			{
				draw_pixel(e, (t_pixel){x, y, inter->obj->color});
				free(inter);
			}
			free(ray);
			++x;
		}
		++y;
	}
}
