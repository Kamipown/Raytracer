/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/14 04:08:04 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_mode(t_bool mode)
{
	if (mode == MODE_NULL)
		ft_putendl("Mode : Null");
	else if (mode == MODE_CAMERA)
		ft_putendl("Mode : Camera");
	else if (mode == MODE_CAMERA_ROT)
		ft_putendl("Mode : Camera Rotation");
	else if (mode == MODE_SELECT)
		ft_putendl("Mode : Selection");
	else if (mode == MODE_SELECT_ROT)
		ft_putendl("Mode : Selection Rotation");
	else if (mode == MODE_TEXTURES)
		ft_putendl("Mode : Textures");
	else if (mode == MODE_BUMPMAPPING)
		ft_putendl("Mode : Bumpmapping");
}

static void	change_mode(t_env *e, int mode)
{
	e->options.mode = mode;
	print_mode(e->options.mode);
	e->options.need_redraw_sub = TRUE;
}

static void	key_hook_move(t_env *e)
{
	if (e->inputs.key_left)
		move_left(e);
	if (e->inputs.key_right)
		move_right(e);
	if (e->inputs.key_up)
		move_up(e);
	if (e->inputs.key_down)
		move_down(e);
	if (e->inputs.key_forward)
		move_forward(e);
	if (e->inputs.key_backward)
		move_backward(e);
}

void		key_hook(t_env *e)
{
	if (e->inputs.escape)
		e->options.quit = TRUE;
	if (e->inputs.key_0)
		change_mode(e, MODE_NULL);
	if (e->inputs.key_1)
		change_mode(e, MODE_CAMERA);
	if (e->inputs.key_2)
		change_mode(e, MODE_CAMERA_ROT);
	if (e->inputs.key_3)
		change_mode(e, MODE_SELECT);
	if (e->inputs.key_4)
		change_mode(e, MODE_SELECT_ROT);
	if (e->inputs.key_5)
		change_mode(e, MODE_TEXTURES);
	if (e->inputs.key_6)
		change_mode(e, MODE_BUMPMAPPING);
	if (e->inputs.key_f)
		toggle_fullscreen(e);
	if (e->inputs.key_e)
		change_effects(e);
	if (e->inputs.key_screenshoot)
		take_screenshoot(e);
	key_hook_move(e);
}

void		mouse_hook(t_env *e)
{
	if (e->inputs.mouse_left && e->event.window.windowID == 1)
	{
		create_ray(&e->scene, (t_vec3)
		{
			e->inputs.mouse_x - (e->scene.current_mode->w / 2),
			e->inputs.mouse_y - (e->scene.current_mode->h / 2),
			0
		});
		e->scene.selected = throw_ray(e, &e->scene.ray);
		if (e->scene.selected.type == SPHERE)
			ft_putendl("Sphere selected");
		else if (e->scene.selected.type == CYLINDER)
			ft_putendl("Cylinder selected");
		else if (e->scene.selected.type == CONE)
			ft_putendl("Cone selected");
		else if (e->scene.selected.type == PLANE)
			ft_putendl("Plane selected");
	}
	else if (e->inputs.mouse_left && e->event.window.windowID == 2)
		mouse_interface(e);
}
