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

static void	init_scene(t_env *e, char *filename)
{
	if (!(e->scene = (t_scene *)malloc(sizeof(t_scene))))
		error(-4, "Unable to create the scene.");
	parse_scene(e->scene, filename);
}

static void	init_minilibx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		error(-5, "Unable to initialize mlx.");
}

static void	init_window(t_env *e)
{
	if (!(e->win = mlx_new_window(e->mlx,
		e->scene->screen_w, e->scene->screen_h, "Rtv1")))
		error(-6, "Unable to create a new window.");
}

static void	init_image(t_env *e)
{
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		error(-7, "Unable to create a new image.");
	if (!(e->img->data = mlx_new_image(e->mlx,
		e->scene->screen_w, e->scene->screen_h)))
		error(-8, "Unable to create image data.");
}

void		init(t_env *e, char *filename)
{
	init_scene(e, filename);
	init_minilibx(e);
	init_window(e);
	init_image(e);
}
