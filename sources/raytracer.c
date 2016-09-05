/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:40:21 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/03 19:40:22 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	throw_ray(t_env *e, t_ray *ray)
{
	if (ray)
		draw_pixel(e, (t_pixel){ray->pos.x, ray->pos.y, 0xcc5555});
}

void		raytrace(t_env *e)
{
	int		x;
	int		y;
	t_ray	*ray;

	ray = init_ray();
	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			update_ray(ray, x, y);
			throw_ray(e, ray);
			++x;
		}
		++y;
	}
	free(ray);
}