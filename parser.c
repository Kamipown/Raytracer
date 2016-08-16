/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:25:27 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/27 16:25:28 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_scene(t_scene *s, char *filename)
{
	char	*data;

	if (!s && 0)
		return ;
	data = read_file(filename);
	ft_putnbr_endl(read_data(data, "config.screen.width"));
	ft_putnbr_endl(read_data(data, "config.screen.height"));
	ft_putnbr_endl(read_data(data, "config.counts.lights"));
	ft_putnbr_endl(read_data(data, "spheres.0.ray"));
	ft_putnbr_endl(read_data(data, "planes.1.size.width"));
	ft_putnbr_endl(read_data(data, "planes.1.size.height"));
	free(data);
}
