/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:47:11 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/18 19:47:12 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_pixel(t_env *e, t_pixel p)
{
	if (p.x > 0 && p.x < e->scene->size.w && p.y > 0 && p.y < e->scene->size.h)
	{
		p.x *= 4;
		p.y *= 4;
		e->img->buf[(p.x++) + (p.y * e->scene->size.w)] = p.color;
		e->img->buf[(p.x++) + (p.y * e->scene->size.w)] = p.color >> 8;
		e->img->buf[(p.x) + (p.y * e->scene->size.w)] = p.color >> 16;
	}
}

void		draw_image(t_env *e)
{
	e->img->buf = mlx_get_data_addr(
		e->img->data,
		&e->img->bpp,
		&e->img->size,
		&e->img->endian);
	raytrace(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->data, 0, 0);
}
