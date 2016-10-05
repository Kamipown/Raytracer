/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 22:40:18 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 16:40:49 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_mode(t_bool mode)
{
	if (mode == MODE_NULL)
		ft_putendl("Mode : Null");
	else if (mode == MODE_CAMERA)
		ft_putendl("Mode : Camera");
	else if (mode == MODE_SELECT)
		ft_putendl("Mode : Selections");
}

void		switch_mode(t_env *e)
{
	if (e->event.key.keysym.sym == SDLK_1)
	{
		if (e->options.mode != MODE_CAMERA)
			e->options.mode = MODE_CAMERA;
		else
			e->options.mode = MODE_NULL;
	}
	else if (e->event.key.keysym.sym == SDLK_2)
	{
		if (e->options.mode != MODE_SELECT)
			e->options.mode = MODE_SELECT;
		else
			e->options.mode = MODE_NULL;
	}
	print_mode(e->options.mode);
}
