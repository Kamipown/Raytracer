/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 03:26:22 by gromon            #+#    #+#             */
/*   Updated: 2016/11/08 04:29:42 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			grayscale_effect(t_color *color)
{
	double gray;

	gray = color->r * 0.3 + color->g * 0.3 + color->b * 0.11;
	color->r = pick_value(gray, 0.0, 1.0);
	color->g = pick_value(gray, 0.0, 1.0);
	color->b = pick_value(gray, 0.0, 1.0);
}

static void			sepia_effect(t_color *color)
{
	color->r = pick_value(color->r * 0.393 + color->g
	* 0.769 + color->b * 0.189, 0.0, 1.0);
	color->g = pick_value(color->r * 0.349 + color->g
	* 0.686 + color->b * 0.168, 0.0, 1.0);
	color->b = pick_value(color->r * 0.272 + color->g
	* 0.534 + color->b * 0.131, 0.0, 1.0);
}

void				select_effects(t_env *e, t_color *color)
{
	if (e->scene.effect == 1)
		grayscale_effect(color);
	else if (e->scene.effect == 2)
		sepia_effect(color);
}

void				change_effects(t_env *e)
{
	e->options.need_redraw = TRUE;
	e->scene.effect = (e->scene.effect + 1) % 3;
}
