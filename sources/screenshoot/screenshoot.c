/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshoot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:47:11 by dcognata          #+#    #+#             */
/*   Updated: 2016/09/17 15:32:16 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		    take_screenshoot(t_env *e)
{
    time_t      rawtime;
    struct tm   *timeinfo;
    char        *name;
    // SDL_Surface *juda;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    name = ft_strjoin(ft_strjoin(ft_itoa(timeinfo->tm_min), ft_itoa(timeinfo->tm_sec)), ".png\"");
    ft_putstr("New screenshoot taked : \"");
    ft_putendl(name);

	// SDL_SaveBMP(SDL_GetWindowSurface(e->win), name);
}
