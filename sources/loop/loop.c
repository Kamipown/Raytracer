/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:47:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 15:50:35 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_options	get_options(void)
{
	t_options opt;

	opt.fullscreen = FALSE;
	opt.quit = FALSE;
	opt.mode = MODE_NULL;
	opt.need_redraw = TRUE;
	return (opt);
}

void				loop(t_env *e)
{
	e->options = get_options();
	init_inputs(&e->inputs);
	while (e->options.quit == FALSE)
	{
		if (e->options.need_redraw)
		{
			draw(e);
			e->options.need_redraw = FALSE;
		}
		get_inputs(e);
		key_hook(e);
		mouse_hook(e);
	}
}
