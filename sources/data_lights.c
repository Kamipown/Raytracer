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

// static void	fill_light(t_scene *s, char *data, int i)
// {

// }

static void	print_lights(t_scene *s)
{
	int		i;

	i = 0;
	ft_putendl("LIGHTS");
	while (i < s->n_light)
	{
		ft_putstr("Light "); ft_putnbr(i); ft_putendl(" :");
		ft_putstr("\tpos x -> "); ft_putnbr(s->lights[i].pos.x); ft_putchar('\n');
		ft_putstr("\tpos y -> "); ft_putnbr(s->lights[i].pos.y); ft_putchar('\n');
		ft_putstr("\tpos z -> "); ft_putnbr(s->lights[i].pos.z); ft_putchar('\n');
		ft_putstr("\tcolor -> "); ft_putnbr(s->lights[i].color); ft_putchar('\n');
		ft_putstr("\tintensity -> "); ft_putnbr(s->lights[i].intensity); ft_putchar('\n');
		++i;
	}
}

void		fill_lights_data(t_scene *s, char *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i < s->n_light)
	{
		str = construct_request_int("lights.#.pos.x", i);
		s->lights[i].pos.x = read_int_data(data, str);
		free(str);
		str = construct_request_int("lights.#.pos.y", i);
		s->lights[i].pos.y = read_int_data(data, str);
		free(str);
		str = construct_request_int("lights.#.pos.z", i);
		s->lights[i].pos.z = read_int_data(data, str);
		free(str);
		str = construct_request_int("lights.#.color", i);
		s->lights[i].color = read_color_data(data, str);
		free(str);
		str = construct_request_int("lights.#.intensity", i);
		s->lights[i].intensity = read_int_data(data, str);
		free(str);
		++i;
	}
	print_lights(s);
}
