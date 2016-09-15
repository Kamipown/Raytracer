/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:47:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/15 17:47:44 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_options	get_options(void)
{
	t_options opt;

	opt.fullscreen = FALSE;
	opt.quit = FALSE;
	return (opt);
}

void				loop(t_env *e)
{
	t_bool need_redraw;

	need_redraw = TRUE;
	e->options = get_options();
	SDL_SetRenderDrawColor(e->renderer, 0, 0, 0, 255);
	SDL_RenderClear(e->renderer);
	while (e->options.quit == FALSE)
	{
		if (need_redraw)
		{
			expose_hook(e);
			need_redraw = FALSE;
		}
		SDL_WaitEvent(&e->event);
		if (e->event.type == SDL_KEYDOWN)
			key_hook(e->event.key.keysym.sym, e);
		if (e->event.type == SDL_QUIT)
				e->options.quit = TRUE;
		SDL_RenderClear(e->renderer);
	}
}
