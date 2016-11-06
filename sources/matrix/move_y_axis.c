/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_y_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:47:39 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/08 22:10:34 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		rotate_up(t_vec3 *v)
{
	double	t;

	t = v->x;
	v->x = v->x * cos(ROT_SPEED * M_PI / 180)
			+ v->z * sin(ROT_SPEED * M_PI / 180);
	v->z = t * -(sin(ROT_SPEED * M_PI / 180))
			+ v->z * cos(ROT_SPEED * M_PI / 180);
}

static void		rotate_down(t_vec3 *v)
{
	double	t;

	t = v->x;
	v->x = v->x * cos(-ROT_SPEED * M_PI / 180)
			+ v->z * sin(-ROT_SPEED * M_PI / 180);
	v->z = t * -(sin(-ROT_SPEED * M_PI / 180))
			+ v->z * cos(-ROT_SPEED * M_PI / 180);
}

void	move_up(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene.selected.obj)
	{
		e->scene.selected.obj->pos.y -= MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_SELECT_ROT && e->scene.selected.obj)
	{
		rotate_up(&e->scene.selected.obj->rot);
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA)
	{
		e->scene.cam.pos.y -= MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.x -= ROT_SPEED;
		if (e->scene.cam.rot.x < 0)
			e->scene.cam.rot.x = 360 + e->scene.cam.rot.x;
		e->options.need_redraw = TRUE;
	}
}

void	move_down(t_env *e)
{
	if (e->options.mode == MODE_SELECT && e->scene.selected.obj)
	{
		e->scene.selected.obj->pos.y += MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_SELECT_ROT && e->scene.selected.obj)
	{
		rotate_down(&e->scene.selected.obj->rot);
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA)
	{
		e->scene.cam.pos.y += MOVE_SPEED;
		e->options.need_redraw = TRUE;
	}
	else if (e->options.mode == MODE_CAMERA_ROT)
	{
		e->scene.cam.rot.x += ROT_SPEED;
		if (e->scene.cam.rot.x >= 360)
			e->scene.cam.rot.x -= 360;
		e->options.need_redraw = TRUE;
	}
}
