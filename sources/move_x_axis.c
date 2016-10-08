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
	if (e->options.mode == MODE_SELECT && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
			e->scene->selected->sphere->pos.x -= MOVE_SPEED;
		else if (e->scene->selected->shape_type == PLANE)
		{
			e->scene->selected->plane->normal.x -= MOVE_SPEED;
			printf("%f\n", e->scene->selected->plane->normal.x);
		}
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
	if (e->options.mode == MODE_SELECT && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
			e->scene->selected->sphere->pos.x += MOVE_SPEED;
		else if (e->scene->selected->shape_type == PLANE)
		{
			e->scene->selected->plane->normal.x += MOVE_SPEED;
			printf("%f\n", e->scene->selected->plane->normal.x);
		}
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA)
	{
		e->scene->cam->pos.x += MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
}
