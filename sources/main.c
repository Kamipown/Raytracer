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
				int tmp = 1;
	e->sdl_opt.fullscreen = FALSE;
	e->sdl_opt.quit = FALSE;
	while (e->sdl_opt.quit == FALSE)
	{
		if (tmp == 1)
		{
			expose_hook(e);
			tmp = 0;
		}
		SDL_WaitEvent(&e->event);
		if (e->event.type == SDL_KEYDOWN)
			key_hook(e->event.key.keysym.sym, e);
		if (e->event.type == SDL_QUIT)
				e->sdl_opt.quit = TRUE;
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
	sdl_loop(e);
	SDL_DestroyWindow(e->sdl_win);
	SDL_Quit();
	return (0);
}
