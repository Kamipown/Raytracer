/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:10:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/10/07 16:19:55 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	test_hit(t_ray *ray, t_cone *c)
{
	if (ray && c)
		return (0);
	return (0);
}

t_cone		*inter_cones(t_env *e, t_ray *ray, int x, int y)
{
	int		i;

	i = 0;
	while (i < e->scene->n_cone)
	{
		if (test_hit(ray, &e->scene->cones[i]))
		{
			draw_pixel(e, (t_pixel){x, y, e->scene->spheres[i].color});
			return (&e->scene->cones[i]);
		}
		++i;
	}
	return (0);
}
