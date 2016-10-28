/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splace <splace@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:32:07 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/28 01:07:13 by splace           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_inputs_keys(t_env *e, t_bool pressed)
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
	else if (e->event.key.keysym.sym == SDLK_f)
		e->inputs.key_f = pressed;
	else if (e->event.key.keysym.sym == SDLK_KP_4)
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
}
