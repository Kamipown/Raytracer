/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:47:11 by dcognata          #+#    #+#             */
/*   Updated: 2016/09/17 15:32:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		draw_background(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

static void		draw_interface(t_env *e)
{
	SDL_RenderCopy(e->renderer_sub, e->interface.background, NULL,
		&((SDL_Rect){0, 0, 300, 600}));
	if (e->options.mode == MODE_CAMERA)
		SDL_RenderCopy(e->renderer_sub, e->interface.checkbox, NULL,
			&((SDL_Rect){27, 392, 18, 18}));
	else if (e->options.mode == MODE_CAMERA_ROT)
		SDL_RenderCopy(e->renderer_sub, e->interface.checkbox, NULL,
			&((SDL_Rect){27, 424, 18, 18}));
	else if (e->options.mode == MODE_SELECT)
		SDL_RenderCopy(e->renderer_sub, e->interface.checkbox, NULL,
			&((SDL_Rect){27, 360, 18, 18}));
	if (e->options.mode == MODE_TEXTURES)
		SDL_RenderCopy(e->renderer_sub, e->interface.checkbox, NULL,
			&((SDL_Rect){27, 495, 18, 18}));
	else if (e->options.mode == MODE_BUMPMAPPING)
		SDL_RenderCopy(e->renderer_sub, e->interface.checkbox, NULL,
			&((SDL_Rect){27, 527, 18, 18}));
	SDL_RenderPresent(e->renderer_sub);
	e->options.need_redraw_sub = FALSE;
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
	if (e->options.need_redraw)
	{
		draw_background(e->renderer);
		raytrace(e);
		SDL_RenderPresent(e->renderer);
	}
	if (e->options.need_redraw_sub)
		draw_interface(e);
}
