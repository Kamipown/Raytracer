/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:49:14 by dcognata          #+#    #+#             */
/*   Updated: 2016/11/03 23:40:39 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_textures(t_env *e)
{
	SDL_FreeSurface(e->textures.map);
	SDL_DestroyTexture(e->interface.background);
	SDL_DestroyTexture(e->interface.checkbox);
}
