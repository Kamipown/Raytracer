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
}
