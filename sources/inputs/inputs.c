/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:20:20 by gromon            #+#    #+#             */
/*   Updated: 2016/11/08 04:15:44 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_inputs(t_inputs *inputs)
{
	inputs->escape = FALSE;
	inputs->key_0 = FALSE;
	inputs->key_1 = FALSE;
	inputs->key_2 = FALSE;
	inputs->key_3 = FALSE;
	inputs->key_4 = FALSE;
	inputs->key_5 = FALSE;
	inputs->key_6 = FALSE;
	inputs->key_f = FALSE;
	inputs->key_e = FALSE;
	inputs->key_left = FALSE;
	inputs->key_right = FALSE;
	inputs->key_up = FALSE;
	inputs->key_down = FALSE;
	inputs->key_forward = FALSE;
	inputs->key_backward = FALSE;
	inputs->mouse_left = FALSE;
	inputs->mouse_x = 0;
	inputs->mouse_y = 0;
	inputs->key_screenshoot = FALSE;
}

static void	reset_inputs(t_inputs *inputs)
{
	inputs->key_0 = FALSE;
	inputs->key_1 = FALSE;
	inputs->key_2 = FALSE;
	inputs->key_3 = FALSE;
	inputs->key_4 = FALSE;
	inputs->key_5 = FALSE;
	inputs->key_6 = FALSE;
	inputs->mouse_left = FALSE;
	inputs->key_screenshoot = FALSE;
}

void		get_inputs(t_env *e)
{
	reset_inputs(&e->inputs);
	while (SDL_PollEvent(&e->event))
	{
		if (e->event.type == SDL_QUIT)
			e->options.quit = TRUE;
		else if (e->event.type == SDL_KEYDOWN)
		{
			get_inputs_keys(e, TRUE);
			get_inputs_keys2(e, TRUE);
		}
		else if (e->event.type == SDL_KEYUP)
		{
			get_inputs_keys(e, FALSE);
			get_inputs_keys2(e, FALSE);
		}
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
			get_inputs_mouse(e);
	}
}
