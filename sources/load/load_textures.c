/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:49:14 by dcognata          #+#    #+#             */
/*   Updated: 2016/04/18 19:49:15 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		load_textures(t_env *e)
{
    /*
     * SDL_Surface 	*marble;
     * getpixel(SDL_Surface *surface, int x, int y)
     */
	if ((e->textures.marble = SDL_LoadBMP("./resources/textures/marble.bmp")) == 0)
		error(-21, (char *)SDL_GetError());
}
