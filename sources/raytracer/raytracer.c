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

	//printf("Camera: (%f, %f, %f)\n", e->scene->cam->pos.x, e->scene->cam->pos.y, e->scene->cam->pos.z);

	y = 0;
	printf("%f %f %f", e->scene->cylinders[0].pos.x, e->scene->cylinders[0].pos.y, e->scene->cylinders[0].pos.z);
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

			// printf("Origin: (%f, %f, %f)\n",
			// 	ray->origin.x, ray->origin.y, ray->origin.z);
			if ((inter = throw_ray(e, ray, 0)))
			{
				// calcul lights
				if (inter->shape_type == SPHERE)
					draw_pixel(e, (t_pixel){x, y, inter->sphere->color});
				else if (inter->shape_type == CYLINDER)
					draw_pixel(e, (t_pixel){x, y, inter->cylinder->color});
				else if (inter->shape_type == CONE)
					draw_pixel(e, (t_pixel){x, y, inter->cone->color});
				else if (inter->shape_type == PLANE)
					draw_pixel(e, (t_pixel){x, y, inter->plane->color});
				free(inter);
			}
			free(ray);
			++x;
		}
		++y;
	}
}
