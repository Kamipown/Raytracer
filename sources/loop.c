/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:47:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/17 15:33:39 by dcognata         ###   ########.fr       */
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
	e->options.need_redraw = TRUE;
	e->options = get_options();
	SDL_SetRenderDrawColor(e->renderer, 0, 0, 0, 255);
	SDL_RenderClear(e->renderer);
	while (e->options.quit == FALSE)
	{
		if (e->options.need_redraw)
		{
			expose_hook(e);
			e->options.need_redraw = FALSE;
		}
		get_inputs(e);
		key_hook(e);
		mouse_hook(e);
		SDL_RenderClear(e->renderer);
	}
}
