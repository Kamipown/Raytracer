/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:33 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/18 19:46:34 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	check(int argc)
{
	if (SCREEN_W < 1 || SCREEN_H < 1)
		error(1, "bad screen size.");
	if (argc < 2)
		error(2, "missing file.");
}

int			main(int argc, char *argv[])
{
	t_env	e;

	check(argc);
	init(&e, argv[1]);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, 2, (1L << 0), key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
