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

void		draw_pixel(char *buf, int x, int y, int color)
{
	if (x > 0 && x < SCREEN_W && y > 0 && y < SCREEN_H)
	{
		x *= 4;
		y *= 4;
		buf[(x++) + (y * SCREEN_W)] = color;
		buf[(x++) + (y * SCREEN_W)] = color >> 8;
		buf[(x) + (y * SCREEN_W)] = color >> 16;
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
	draw_pixel(buf, 5, 5, 0xff0000);
	mlx_put_image_to_window(e->mlx, e->win, e->img->data, 0, 0);
}
