/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 17:47:02 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

void	key_hook(t_env *e)
{
	if (e->inputs.escape)
		e->options.quit = TRUE;
	if (e->inputs.key_f && !e->options.fullscreen)
	{
		e->options.fullscreen = TRUE;
		e->options.need_redraw = TRUE;
		SDL_SetWindowFullscreen(e->win, SDL_WINDOW_FULLSCREEN);
	}
	else if (e->inputs.key_f && e->options.fullscreen)
	{
		e->options.fullscreen = FALSE;
		e->options.need_redraw = TRUE;
		SDL_SetWindowFullscreen(e->win, 0);
	}
	if (e->inputs.key_left && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
		{
			e->scene->selected->sphere->pos.x -= 20;
			e->options.need_redraw = TRUE;
		}
	}
	if (e->inputs.key_right && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
		{
			e->scene->selected->sphere->pos.x += 20;
			e->options.need_redraw = TRUE;
		}
	}
	if (e->inputs.key_up && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
		{
			e->scene->selected->sphere->pos.y -= 20;
			e->options.need_redraw = TRUE;
		}
	}
	if (e->inputs.key_down && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
		{
			e->scene->selected->sphere->pos.y += 20;
			e->options.need_redraw = TRUE;
		}
	}
	if (e->inputs.key_z_more && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
		{
			e->scene->selected->sphere->pos.z += 20;
			e->options.need_redraw = TRUE;
		}
	}
	if (e->inputs.key_z_less && e->scene->selected)
	{
		if (e->scene->selected->shape_type == SPHERE)
		{
			e->scene->selected->sphere->pos.z -= 20;
			e->options.need_redraw = TRUE;
		}
	}
}

void	mouse_hook(t_env *e)
{
	t_ray	*ray;

	if (e->inputs.mouse_left)
	{
		ray = create_ray(&e->scene->cam->pos, (t_vec3)
		{
			e->inputs.mouse_x - (e->scene->size.w / 2),
			e->inputs.mouse_y - (e->scene->size.h / 2),
			e->scene->cam->focal_dist
		});
		e->scene->selected = throw_ray(e, ray, e->inputs.mouse_x, e->inputs.mouse_y);
		if (e->scene->selected->shape_type == SPHERE)
			ft_putendl("Sphere selected");
		else if (e->scene->selected->shape_type == CYLINDER)
			ft_putendl("Cylinder selected");
		else if (e->scene->selected->shape_type == CONE)
			ft_putendl("Cone selected");
		else if (e->scene->selected->shape_type == PLANE)
			ft_putendl("Plane selected");
		free(ray);
	}
}
