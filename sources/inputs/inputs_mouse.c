/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:32:19 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/06 17:32:21 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_inputs_mouse(t_env *e)
{
	if (e->event.button.button == 1)
		e->inputs.mouse_left = TRUE;
	SDL_GetMouseState(&e->inputs.mouse_x, &e->inputs.mouse_y);
}
