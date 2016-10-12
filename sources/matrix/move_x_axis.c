/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_x_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:47:34 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/08 22:10:18 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	move_left(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene->selected->type > 0)
	{
		e->scene->selected->obj->pos.x -= MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA)
	{
		e->scene->cam->pos.x -= MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
}

void	move_right(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene->selected->type > 0)
	{
		e->scene->selected->obj->pos.x += MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA)
	{
		e->scene->cam->pos.x += MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
}
