/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:49:14 by dcognata          #+#    #+#             */
/*   Updated: 2016/11/02 23:19:00 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		load_textures(t_env *e)
{
	if ((e->textures.map = SDL_LoadBMP("earth.bmp")) == 0)
		error(-21, (char *)SDL_GetError());
}
