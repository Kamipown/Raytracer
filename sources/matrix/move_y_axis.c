/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_y_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:47:39 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/14 03:54:59 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	move_up(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene.selected.obj)
		e->scene.selected.obj->pos.y -= MOVE_SPEED;
	else if (e->options.mode == MODE_SELECT_ROT && e->scene.selected.obj)
	{
		if (e->scene.selected.obj->type == PLANE)
			rotate_normal_down(&e->scene.selected.obj->rot);
		else
			rotate_down(&e->scene.selected.obj->rot);
	}
	else if (e->options.mode == MODE_CAMERA)
		e->scene.cam.pos.y -= MOVE_SPEED;
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.x -= ROT_SPEED;
		if (e->scene.cam.rot.x < 0)
			e->scene.cam.rot.x = 360 + e->scene.cam.rot.x;
	}
	if (e->options.mode == MODE_SELECT
		|| e->options.mode == MODE_SELECT_ROT
		|| e->options.mode == MODE_CAMERA
		|| e->options.mode == MODE_CAMERA_ROT)
		e->options.need_redraw = TRUE;
}

void	move_down(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene.selected.obj)
		e->scene.selected.obj->pos.y += MOVE_SPEED;
	else if (e->options.mode == MODE_SELECT_ROT && e->scene.selected.obj)
	{
		if (e->scene.selected.obj->type == PLANE)
			rotate_normal_up(&e->scene.selected.obj->rot);
		else
			rotate_up(&e->scene.selected.obj->rot);
	}
	else if (e->options.mode == MODE_CAMERA)
		e->scene.cam.pos.y += MOVE_SPEED;
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.x += ROT_SPEED;
		if (e->scene.cam.rot.x >= 360)
			e->scene.cam.rot.x -= 360;
	}
	if (e->options.mode == MODE_SELECT
		|| e->options.mode == MODE_SELECT_ROT
		|| e->options.mode == MODE_CAMERA
		|| e->options.mode == MODE_CAMERA_ROT)
		e->options.need_redraw = TRUE;
}
