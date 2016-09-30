/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:56 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/17 15:24:28 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		   expose_hook(t_env *e)
{
    draw_background(e);
	draw_image(e);
	return (0);
}

void		key_hook(t_env *e)
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
}

#include <stdio.h>

void     mouse_hook(t_env *e)
{
    t_ray   *ray;

    if (e->inputs.mouse_left)
    {
        ray = create_ray(&e->scene->cam->pos, (t_vec3)
        {
            e->inputs.mouse_x - (e->scene->size.w / 2),
            e->inputs.mouse_y - (e->scene->size.h / 2),
            e->scene->cam->focal_dist
        });
        printf("Rayon lance :\n origin(%f, %f, %f) - direction(%f, %f, %f)\n",
        ray->origin.x,
        ray->origin.y,
        ray->origin.z,
        ray->dir.x,
        ray->dir.y,
        ray->dir.z);
        throw_ray(e, ray, e->inputs.mouse_x, e->inputs.mouse_y);
        free(ray);
    }
}
