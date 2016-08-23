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

void		draw_pixel(char *buf, t_pixel p, t_size *size)
{
	if (p.x > 0 && p.x < size->w && p.y > 0 && p.y < size->h)
	{
		p.x *= 4;
		p.y *= 4;
		buf[(p.x++) + (p.y * size->w)] = p.color;
		buf[(p.x++) + (p.y * size->w)] = p.color >> 8;
		buf[(p.x) + (p.y * size->w)] = p.color >> 16;
	}
}

void		draw_image(t_env *e)
{
	char	*buf;

	buf = mlx_get_data_addr(
		e->img->data,
		&e->img->bpp,
		&e->img->size,
		&e->img->endian);
	draw_pixel(buf, (t_pixel){100, 100, 0xff0000}, &e->scene->size);
	mlx_put_image_to_window(e->mlx, e->win, e->img->data, 0, 0);
}
