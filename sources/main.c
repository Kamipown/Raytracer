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

void		sdl_init(t_env *e)
{
	if ((e->sdl_win = SDL_CreateWindow("RT - 42", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, e->scene->size.w, e->scene->size.h,
		SDL_WINDOW_RESIZABLE)) == NULL)
		error(-20, (char *)SDL_GetError());
}

void		sdl_loop(t_env *e)
{
	t_boolean quit;

	quit = FALSE;
	while (quit == FALSE)
	{
		SDL_WaitEvent(&e->event);
		if (e->event.type == SDL_KEYDOWN)
			if (e->event.key.keysym.sym == SDLK_ESCAPE)
				quit = TRUE;
		if (e->event.type == SDL_QUIT)
				quit = TRUE;

	}
}

int			main(int argc, char *argv[])
{
	t_env	*e;

	check(argc);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		error(-3, "Unable to initialize environment.");
	init(e, argv[1]);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		error(-20, (char *)SDL_GetError());

	/* ajout sdl */
	sdl_init(e);
	sdl_loop(e);
	SDL_DestroyWindow(e->sdl_win);
	SDL_Quit();

	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
