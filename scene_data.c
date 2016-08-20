/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 05:01:29 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/20 05:01:30 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	fill_screen_data(t_scene *scene, char *data)
{
	int		sw;
	int		sh;

	sw = read_int_data(data, "config.screen.width");
	sh = read_int_data(data, "config.screen.height");
	scene->screen_w = sw >= MIN_SCREEN_W && sw <= MAX_SCREEN_W ? sw : SCREEN_W;
	scene->screen_h = sh >= MIN_SCREEN_H && sh <= MAX_SCREEN_H ? sh : SCREEN_H;
}
