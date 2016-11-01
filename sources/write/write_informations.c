/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_informations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:47:11 by dcognata          #+#    #+#             */
/*   Updated: 2016/09/17 15:32:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			write_informations(t_env *e)
{
    TTF_Init();
	if(TTF_Init() == -1)
	    error(-25, "Unable to initialize fonts environment.");

	//
	TTF_Font *police = NULL;
	SDL_Rect position;
	position.x = 0;
	position.y = 0;
	police = TTF_OpenFont("./resources/fonts/Oswald-Bold.ttf", 10);

	SDL_Color White = {255, 255, 255, 1};
	SDL_Surface* surface_message = TTF_RenderText_Solid(police, "PD TOUS DES", White);
	SDL_Texture* message = SDL_CreateTextureFromSurface(e->renderer, surface_message);
	SDL_Rect message_rect;
	message_rect.x = 0; 
	message_rect.y = 0;
	message_rect.w = 80;
	message_rect.h = 20;
	SDL_RenderCopy(e->renderer, message, NULL, &message_rect);
	
	SDL_DestroyTexture(message);
	SDL_FreeSurface(surface_message);
	
	//
	TTF_CloseFont(police);
	TTF_Quit();
}
