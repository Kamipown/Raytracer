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

static void		draw_background(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void			draw_pixel(t_env *e, t_pixel p)
{
	if (p.x > 0 && p.x < e->scene.current_mode->w
		&& p.y > 0 && p.y < e->scene.current_mode->h)
	{
		SDL_SetRenderDrawColor(e->renderer,
			p.color.r,
			p.color.g,
			p.color.b,
			255);
		SDL_RenderDrawPoint(e->renderer, p.x, p.y);
	}
}

void			draw(t_env *e)
{
	draw_background(e->renderer);
	raytrace(e);
	SDL_RenderPresent(e->renderer);
}
