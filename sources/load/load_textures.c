/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:49:14 by dcognata          #+#    #+#             */
/*   Updated: 2016/11/04 01:28:27 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			load_textures(t_env *e)
{
	SDL_Surface	*background;
	SDL_Surface	*checkbox;

	if ((e->textures.map = SDL_LoadBMP("./resources/textures/earth.bmp")) == 0)
		error(-21, (char *)SDL_GetError());
	if ((background = SDL_LoadBMP("./resources/interface/background.bmp")) == 0)
		error(-21, (char *)SDL_GetError());
	if ((checkbox = SDL_LoadBMP("./resources/interface/checkbox.bmp")) == 0)
		error(-21, (char *)SDL_GetError());
	e->interface.background = SDL_CreateTextureFromSurface(e->renderer_sub,
	background);
	e->interface.checkbox = SDL_CreateTextureFromSurface(e->renderer_sub,
	checkbox);
	SDL_FreeSurface(background);
	SDL_FreeSurface(checkbox);
}
