/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:49:14 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/08 04:04:49 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		error(-20, (char *)SDL_GetError());
}

static void	init_scene(t_env *e, char *filename)
{
	parse_scene(&e->scene, filename);
	e->scene.selected.obj = 0;
	e->scene.effect = 0;
}

static void	init_window(t_env *e)
{
	SDL_Surface *surface;

	if ((e->win = SDL_CreateWindow("RT - 42", MAIN_POS_X,
		MAIN_POS_Y, e->scene.size.w, e->scene.size.h,
		0)) == NULL)
		error(-21, (char *)SDL_GetError());
	SDL_GetWindowDisplayMode(e->win, &e->scene.mode_win);
	SDL_GetDesktopDisplayMode(0, &e->scene.mode_fs);
	e->scene.current_mode = &e->scene.mode_win;
	if ((surface = SDL_LoadBMP("./resources/icon.bmp")) == 0)
		error(-21, (char *)SDL_GetError());
	SDL_SetWindowIcon(e->win, surface);
	SDL_FreeSurface(surface);
	if ((e->win_sub = SDL_CreateWindow("Yatangaki Center", MAIN_POS_X - 300,
	MAIN_POS_Y, 300, 600, 0)) == NULL)
		error(-21, (char *)SDL_GetError());
}

static void	init_image(t_env *e)
{
	if ((e->renderer = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_SOFTWARE))
		== NULL)
		error(-22, (char *)SDL_GetError());
	if ((e->renderer_sub =
		SDL_CreateRenderer(e->win_sub, -1, SDL_RENDERER_ACCELERATED)) == NULL)
		error(-22, (char *)SDL_GetError());
}

void		init(t_env *e, char *filename)
{
	init_sdl();
	init_scene(e, filename);
	init_window(e);
	init_image(e);
}
