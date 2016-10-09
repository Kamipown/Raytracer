/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 11:01:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/08/29 11:01:16 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	print_lights(t_scene *s)
{
	int		i;

	i = 0;
	while (i < s->n_light)
	{
		ft_putstr("Light ");
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putstr("\tpos(");
		ft_putnbr(s->lights[i].pos.x);
		ft_putstr(", ");
		ft_putnbr(s->lights[i].pos.y);
		ft_putstr(", ");
		ft_putnbr(s->lights[i].pos.z);
		ft_putstr(") color(");
		ft_putnbr(s->lights[i].color);
		ft_putstr(") intensity(");
		ft_putnbr(s->lights[i].intensity);
		ft_putendl(")");
		++i;
	}
	ft_putchar('\n');
}

void		fill_lights_data(t_scene *s, char *data)
{
	int		i;
	char	*request;

	i = 0;
	while (i < s->n_light)
	{
		request = construct_request_int("lights.#.pos.x", i);
		s->lights[i].pos.x = read_int_data(data, request);
		free(request);
		request = construct_request_int("lights.#.pos.y", i);
		s->lights[i].pos.y = read_int_data(data, request);
		free(request);
		request = construct_request_int("lights.#.pos.z", i);
		s->lights[i].pos.z = read_int_data(data, request);
		free(request);
		request = construct_request_int("lights.#.color", i);
		s->lights[i].color = read_color_data(data, request);
		free(request);
		request = construct_request_int("lights.#.intensity", i);
		s->lights[i].intensity = read_int_data(data, request);
		free(request);
		++i;
	}
	print_lights(s);
}
