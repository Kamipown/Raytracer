/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:33 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/10 13:23:40 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	check(int argc)
{
	if (SCREEN_W < 1 || SCREEN_H < 1)
		error(-1, "Bad screen size.");
	if (argc < 2)
		error(-2, "Missing file.");
}

void		sdl_loop(t_env *e)
{
	t_boolean quit = FALSE;

	e->sdl_win = NULL;
	e->sdl_win = SDL_CreateWindow(
		"RT - 42",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		e->scene->size.w,                               // width, in pixels
		e->scene->size.h,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);
	if(e->sdl_win)
	{
		while (quit == FALSE)
		{
			SDL_WaitEvent(&e->event);
			switch(e->event.type) {
				case SDL_KEYDOWN:
					switch(e->event.key.keysym.sym) {
					case SDLK_ESCAPE:
						quit = TRUE;
						break;
					}
					break;
			}
		}
		SDL_DestroyWindow(e->sdl_win);
	}
	else
		error(-20, (char *)SDL_GetError());
	SDL_Quit();
}

int			main(int argc, char *argv[])
{
	t_env	*e;

	check(argc);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		error(-3, "Unable to initialize environment.");
	init(e, argv[1]);
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
		error(-20, (char *)SDL_GetError());
	sdl_loop(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
