/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_x_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:47:34 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/04 01:23:10 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	move_left2(t_env *e)
{
	if (e->scene.selected)
	{
		if (e->options.mode == MODE_SELECT)
		{
			e->scene.selected->obj->pos.x -= MOVE_SPEED;
			e->options.need_redraw = TRUE;
		}
		else if (e->options.mode == MODE_SELECT_ROT)
		{
			rotate_left(&e->scene.selected->obj->rot);
			e->options.need_redraw = TRUE;
		}
		else if (e->options.mode == MODE_TEXTURES)
		{
			e->scene.selected->obj->textures -= 1;
			e->options.need_redraw = TRUE;
		}
		else if (e->options.mode == MODE_BUMPMAPPING)
		{
			e->scene.selected->obj->textures -= 0.1;
			e->options.need_redraw = TRUE;
		}
	}
}

void	move_left(t_env *e)
{
	move_left2(e);
	if (e->options.mode == MODE_CAMERA)
	{
		e->scene.cam.pos.x -= MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.y -= ROT_SPEED;
		if (e->scene.cam.rot.y < 0)
			e->scene.cam.rot.y = 360 + e->scene.cam.rot.y;
		e->options.need_redraw = TRUE;
	}
}

void	move_right2(t_env *e)
{
	if (e->scene.selected)
	{
		if (e->options.mode == MODE_SELECT)
		{
			e->scene.selected->obj->pos.x += MOVE_SPEED;
			e->options.need_redraw = TRUE;
		}
		else if (e->options.mode == MODE_SELECT_ROT)
		{
			rotate_right(&e->scene.selected->obj->rot);
			e->options.need_redraw = TRUE;
		}
		else if (e->options.mode == MODE_TEXTURES)
		{
			e->scene.selected->obj->textures += 1;
			e->options.need_redraw = TRUE;
		}
		else if (e->options.mode == MODE_BUMPMAPPING)
		{
			e->scene.selected->obj->bump += 0.1;
			e->options.need_redraw = TRUE;
		}
	}
}

void	move_right(t_env *e)
{
	move_right2(e);
	if (e->options.mode == MODE_CAMERA)
	{
		e->scene.cam.pos.x += MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.y += ROT_SPEED;
		if (e->scene.cam.rot.y >= 360)
			e->scene.cam.rot.y -= 360;
		e->options.need_redraw = TRUE;
	}
}
