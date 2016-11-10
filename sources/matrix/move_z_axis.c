/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_z_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:47:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/08 22:10:42 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	move_forward(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene.selected.obj)
		e->scene.selected.obj->pos.z += MOVE_SPEED;
	else if (e->options.mode == MODE_SELECT_ROT && e->scene.selected.obj)
	{
		if (e->scene.selected.obj->type == PLANE)
			rotate_normal_forward(&e->scene.selected.obj->rot);
		else
			rotate_forward(&e->scene.selected.obj->rot);
	}
	else if (e->options.mode == MODE_CAMERA)
		e->scene.cam.pos.z += MOVE_SPEED;
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.z -= ROT_SPEED;
		if (e->scene.cam.rot.z < 0)
			e->scene.cam.rot.z = 360 + e->scene.cam.rot.z;
	}
	if (e->options.mode == MODE_SELECT
		|| e->options.mode == MODE_SELECT_ROT
		|| e->options.mode == MODE_CAMERA
		|| e->options.mode == MODE_CAMERA_ROT)
		e->options.need_redraw = TRUE;
}

void	move_backward(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene.selected.obj)
		e->scene.selected.obj->pos.z -= MOVE_SPEED;
	else if (e->options.mode == MODE_SELECT_ROT && e->scene.selected.obj)
	{
		if (e->scene.selected.obj->type == PLANE)
			rotate_normal_backward(&e->scene.selected.obj->rot);
		else
			rotate_backward(&e->scene.selected.obj->rot);
	}
	else if (e->options.mode == MODE_CAMERA)
		e->scene.cam.pos.z -= MOVE_SPEED;
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.z += ROT_SPEED;
		if (e->scene.cam.rot.z >= 360)
			e->scene.cam.rot.z -= 360;
	}
	if (e->options.mode == MODE_SELECT
		|| e->options.mode == MODE_SELECT_ROT
		|| e->options.mode == MODE_CAMERA
		|| e->options.mode == MODE_CAMERA_ROT)
		e->options.need_redraw = TRUE;
}
