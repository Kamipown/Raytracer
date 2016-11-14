/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:13:23 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/28 01:05:05 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	toggle_fullscreen(t_env *e)
{
	if (e->options.fullscreen)
	{
		e->options.fullscreen = FALSE;
		SDL_SetWindowFullscreen(e->win, 0);
		e->scene.current_mode = &e->scene.mode_win;
		e->scene.cam.focal_dist = (e->scene.current_mode->w / 2
			/ (fabs(tan(e->scene.cam.fov / 2))));
		e->scene.cam.pos = (t_vec3){0, 0, -e->scene.cam.focal_dist};
	}
	else
	{
		e->options.fullscreen = TRUE;
		SDL_SetWindowFullscreen(e->win, SDL_WINDOW_FULLSCREEN_DESKTOP);
		e->scene.current_mode = &e->scene.mode_fs;
		e->scene.cam.focal_dist = (e->scene.current_mode->w / 2
			/ (fabs(tan(e->scene.cam.fov / 2))));
		e->scene.cam.pos = (t_vec3){0, 0, -e->scene.cam.focal_dist};
	}
	e->options.need_redraw = TRUE;
}
