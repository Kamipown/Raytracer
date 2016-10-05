/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 22:40:18 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/30 22:40:19 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	reset_inputs(t_inputs *inputs)
{
	inputs->escape = FALSE;
	inputs->key_f = FALSE;
	inputs->key_left = FALSE;
	inputs->key_right = FALSE;
	inputs->key_up = FALSE;
	inputs->key_down = FALSE;
	inputs->mouse_left = FALSE;
	inputs->mouse_x = 0;
	inputs->mouse_y = 0;
}

void	get_inputs(t_env *e)
{
	reset_inputs(&e->inputs);
	while (SDL_PollEvent(&e->event))
	{
		if (e->event.type == SDL_QUIT)
			e->options.quit = TRUE;
		else if (e->event.type == SDL_KEYDOWN)
		{
			if (e->event.key.keysym.sym == SDLK_ESCAPE)
				e->inputs.escape = TRUE;
			else if (e->event.key.keysym.sym == SDLK_f)
				e->inputs.key_f = TRUE;
			else if (e->event.key.keysym.sym == SDLK_LEFT)
				e->inputs.key_left = TRUE;
			else if (e->event.key.keysym.sym == SDLK_RIGHT)
				e->inputs.key_right = TRUE;
			else if (e->event.key.keysym.sym == SDLK_UP)
				e->inputs.key_up = TRUE;
			else if (e->event.key.keysym.sym == SDLK_DOWN)
				e->inputs.key_down = TRUE;
		}
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e->event.button.button == 1)
				e->inputs.mouse_left = TRUE;
			SDL_GetMouseState(&e->inputs.mouse_x, &e->inputs.mouse_y);
		}
	}
}
