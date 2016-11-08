/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:20:30 by gromon            #+#    #+#             */
/*   Updated: 2016/11/08 04:16:08 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_inputs_keys(t_env *e, t_bool pressed)
{
	if (e->event.key.keysym.sym == SDLK_ESCAPE)
		e->inputs.escape = pressed;
	else if (e->event.key.keysym.sym == SDLK_0)
		e->inputs.key_0 = pressed;
	else if (e->event.key.keysym.sym == SDLK_1)
		e->inputs.key_1 = pressed;
	else if (e->event.key.keysym.sym == SDLK_2)
		e->inputs.key_2 = pressed;
	else if (e->event.key.keysym.sym == SDLK_3)
		e->inputs.key_3 = pressed;
	else if (e->event.key.keysym.sym == SDLK_4)
		e->inputs.key_4 = pressed;
	else if (e->event.key.keysym.sym == SDLK_5)
		e->inputs.key_5 = pressed;
	else if (e->event.key.keysym.sym == SDLK_6)
		e->inputs.key_6 = pressed;
	else if (e->event.key.keysym.sym == SDLK_f)
		e->inputs.key_f = pressed;
	else if (e->event.key.keysym.sym == SDLK_e)
		e->inputs.key_e = pressed;
}

void	get_inputs_keys2(t_env *e, t_bool pressed)
{
	if (e->event.key.keysym.sym == SDLK_KP_4)
		e->inputs.key_left = pressed;
	else if (e->event.key.keysym.sym == SDLK_KP_6)
		e->inputs.key_right = pressed;
	else if (e->event.key.keysym.sym == SDLK_KP_8)
		e->inputs.key_up = pressed;
	else if (e->event.key.keysym.sym == SDLK_KP_2)
		e->inputs.key_down = pressed;
	else if (e->event.key.keysym.sym == SDLK_KP_9)
		e->inputs.key_forward = pressed;
	else if (e->event.key.keysym.sym == SDLK_KP_7)
		e->inputs.key_backward = pressed;
	else if (e->event.key.keysym.sym == SDLK_9)
		e->inputs.key_screenshoot = pressed;
}
