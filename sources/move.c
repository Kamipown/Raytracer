/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:40:09 by dcognata          #+#    #+#             */
/*   Updated: 2016/10/05 17:47:13 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	move_select(t_env *e)
{
	if (e->event.key.keysym.sym == SDLK_KP_2)
		e->inputs.key_down = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_6)
		e->inputs.key_right = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_8)
		e->inputs.key_up = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_4)
		e->inputs.key_left = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_9)
		e->inputs.key_z_more = TRUE;
	else if (e->event.key.keysym.sym == SDLK_KP_7)
		e->inputs.key_z_less = TRUE;

}

static void	move_camera(t_env *e)
{

}

void		move(t_env *e)
{
	if (e->options.mode != MODE_CAMERA)
	{
		move_camera(e);
	}
	else if (e->options.mode != MODE_SELECT)
	{
		move_select(e);
	}
}
