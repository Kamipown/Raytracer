/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:49:14 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/18 19:49:15 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init(t_env *e, char *filename)
{
	if (!(e->mlx = mlx_init()))
		error(-4, "Unable to initialize mlx.");
	if (!(e->win = mlx_new_window(e->mlx, SCREEN_W, SCREEN_H, "Rtv1")))
		error(-5, "Unable to create a new window.");
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		error(-6, "Unable to create a new image.");
	if (!(e->img->data = mlx_new_image(e->mlx, SCREEN_W, SCREEN_H)))
		error(-7, "Unable to create image data.");
	if (!(e->scene = (t_scene *)malloc(sizeof(t_scene))))
		error(-8, "Unable to create the scene.");
	parse_scene(e->scene, filename);
}
