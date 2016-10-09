/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:32:07 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/06 17:32:09 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_inputs_keys(t_env *e)
{
	if (e->event.key.keysym.sym == SDLK_ESCAPE)
		e->inputs.escape = TRUE;

	// Numbers
	else if (e->event.key.keysym.sym == SDLK_1)
		e->inputs.key_1 = TRUE;
	else if (e->event.key.keysym.sym == SDLK_2)
		e->inputs.key_2 = TRUE;

	// Letters
	else if (e->event.key.keysym.sym == SDLK_f)
		e->inputs.key_f = TRUE;

	// Keypad
	else if (e->event.key.keysym.sym == SDLK_KP_4)
		e->inputs.key_left = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_6)
		e->inputs.key_right = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_8)
		e->inputs.key_up = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_2)
		e->inputs.key_down = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_9)
		e->inputs.key_forward = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_7)
		e->inputs.key_backward = TRUE;
}
