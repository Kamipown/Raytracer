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
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, SCREEN_W, SCREEN_H, "Rtv1");
	e->img = (t_img *)malloc(sizeof(t_img));
	e->img->data = mlx_new_image(e->mlx, SCREEN_W, SCREEN_H);
	e->scene = (t_scene *)malloc(sizeof(t_scene));
	parse_scene(e->scene, filename);
}
