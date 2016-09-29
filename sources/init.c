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

static void	init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		error(-20, (char *)SDL_GetError());
}

static void	init_scene(t_env *e, char *filename)
{
	if (!(e->scene = (t_scene *)malloc(sizeof(t_scene))))
		error(-4, "Unable to create the scene.");
	parse_scene(e->scene, filename);
}

static void	init_window(t_env *e)
{
	if ((e->win = SDL_CreateWindow("RT - 42", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, e->scene->size.w, e->scene->size.h,
		SDL_WINDOW_RESIZABLE)) == NULL)
		error(-21, (char *)SDL_GetError());
}

static void	init_image(t_env *e)
{
	if ((e->renderer = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_ACCELERATED)) == NULL)
		error(-22, (char *)SDL_GetError());
}

void		init(t_env *e, char *filename)
{
	init_sdl();
	init_scene(e, filename);
	init_window(e);
	init_image(e);
}
