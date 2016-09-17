/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:47:11 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/17 15:32:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_pixel(t_env *e, t_pixel p)
{
	if (p.x > 0 && p.x < e->scene->size.w && p.y > 0 && p.y < e->scene->size.h)
	{
        SDL_SetRenderDrawColor(e->renderer, p.color >> 16, p.color >> 8, p.color, 255);
        SDL_RenderDrawPoint(e->renderer, p.x, p.y);
	}
}

void		draw_background(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e->scene->size.h)
	{
		x = 0;
		while (x < e->scene->size.w)
		{
			draw_pixel(e, (t_pixel){x, y, 0x606366});
			++x;
		}
		++y;
	}
}

void		draw_image(t_env *e)
{
	raytrace(e);
    SDL_RenderPresent(e->renderer);
}
