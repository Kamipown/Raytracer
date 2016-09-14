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
	t_boolean quit;
	t_boolean fullscreen;

	fullscreen = FALSE;
	quit = FALSE;
	while (quit == FALSE)
	{
		SDL_SetRenderDrawColor(e->renderer, 255, 0, 0, 255);
		SDL_RenderPresent(e->renderer);
		SDL_WaitEvent(&e->event);
		if (e->event.type == SDL_KEYDOWN)
		{
			if (e->event.key.keysym.sym == SDLK_ESCAPE)
				quit = TRUE;
			if (e->event.key.keysym.sym == SDLK_f && fullscreen == FALSE)
			{
				fullscreen = TRUE;
				SDL_SetWindowFullscreen(e->sdl_win, SDL_WINDOW_FULLSCREEN);
			}
			else if (e->event.key.keysym.sym == SDLK_f && fullscreen == TRUE)
			{
				fullscreen = FALSE;
				SDL_SetWindowFullscreen(e->sdl_win, 0);
			}
		}
		if (e->event.type == SDL_QUIT)
				quit = TRUE;
		SDL_RenderClear(e->renderer);
	}
}

int			main(int argc, char *argv[])
{
	t_env	*e;

	check(argc);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		error(-3, "Unable to initialize environment.");
	init(e, argv[1]);
	/* ajout sdl */
	sdl_loop(e);
	SDL_DestroyWindow(e->sdl_win);
	SDL_Quit();
	return (0);
}
