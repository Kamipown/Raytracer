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

static void	reset_inputs(t_inputs *inputs)
{
	inputs->escape = FALSE;
	inputs->key_1 = FALSE;
	inputs->key_2 = FALSE;
	inputs->key_f = FALSE;
	inputs->key_left = FALSE;
	inputs->key_right = FALSE;
	inputs->key_up = FALSE;
	inputs->key_down = FALSE;
	inputs->key_forward = FALSE;
	inputs->key_backward = FALSE;
	inputs->mouse_left = FALSE;
	inputs->mouse_x = 0;
	inputs->mouse_y = 0;
}

void		get_inputs(t_env *e)
{
	reset_inputs(&e->inputs);
	while (SDL_PollEvent(&e->event))
	{
		if (e->event.type == SDL_QUIT)
			e->options.quit = TRUE;
		else if (e->event.type == SDL_KEYDOWN)
			get_inputs_keys(e);
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
			get_inputs_mouse(e);
	}
}
