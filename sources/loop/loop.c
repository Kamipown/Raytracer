/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:47:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/09 23:59:02 by vmontagn         ###   ########.fr       */
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
	opt.need_redraw_sub = TRUE;
	opt.first_loop = TRUE;
	return (opt);
}

void				loop(t_env *e)
{
	e->options = get_options();
	init_inputs(&e->inputs);
	while (e->options.quit == FALSE)
	{
		if ((e->options.need_redraw || e->options.need_redraw_sub)
			&& e->options.first_loop == FALSE)
		{
			if (e->scene.selected.obj)
				printf("%f %f %f\n", e->scene.selected.obj->rot.x,e->scene.selected.obj->rot.y,e->scene.selected.obj->rot.z);
			draw(e);
			e->options.need_redraw = FALSE;
			e->options.need_redraw_sub = FALSE;
		}
		if (e->options.first_loop == TRUE)
			e->options.first_loop = FALSE;
		get_inputs(e);
		key_hook(e);
		mouse_hook(e);
	}
}
