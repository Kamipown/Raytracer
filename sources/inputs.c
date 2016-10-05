/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 22:40:18 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 17:21:00 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		reset_inputs(t_inputs *inputs)
{
	inputs->escape = FALSE;
	inputs->key_f = FALSE;
	inputs->key_left = FALSE;
	inputs->key_right = FALSE;
	inputs->key_up = FALSE;
	inputs->key_down = FALSE;
	inputs->key_z_less = FALSE;
	inputs->key_z_more = FALSE;
	inputs->mouse_left = FALSE;
	inputs->mouse_x = 0;
	inputs->mouse_y = 0;
}

static void	get_key(t_env *e)
{
	if (e->event.key.keysym.sym == SDLK_ESCAPE)
		e->inputs.escape = TRUE;
	else if (e->event.key.keysym.sym == SDLK_f)
		e->inputs.key_f = TRUE;
	else if (((e->event.key.keysym.sym == SDLK_KP_2) ||
		(e->event.key.keysym.sym == SDLK_KP_4) ||
		(e->event.key.keysym.sym == SDLK_KP_6) ||
		(e->event.key.keysym.sym == SDLK_KP_8) ||
		(e->event.key.keysym.sym == SDLK_KP_7) ||
		(e->event.key.keysym.sym == SDLK_KP_9)) &&
		(e->options.mode != MODE_NULL))
		move(e);
	else if ((e->event.key.keysym.sym == SDLK_1) ||
		(e->event.key.keysym.sym == SDLK_2))
		switch_mode(e);
}

void		get_inputs(t_env *e)
{
	reset_inputs(&e->inputs);
	while (SDL_PollEvent(&e->event))
	{
		if (e->event.type == SDL_QUIT)
			e->options.quit = TRUE;
		else if (e->event.type == SDL_KEYDOWN)
			get_key(e);
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
		{
			e->inputs.mouse_left = (1) ? TRUE : FALSE;
			SDL_GetMouseState(&e->inputs.mouse_x, &e->inputs.mouse_y);
		}
	}
}
