/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:13:23 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/06 18:13:24 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	toggle_fullscreen(t_env *e)
{
	if (e->options.fullscreen)
	{
		e->options.fullscreen = FALSE;
		e->options.need_redraw = TRUE;
		SDL_SetWindowFullscreen(e->win, 0);
	}
	else
	{
		e->options.fullscreen = TRUE;
		e->options.need_redraw = TRUE;
		SDL_SetWindowFullscreen(e->win, SDL_WINDOW_FULLSCREEN);
	}
}
