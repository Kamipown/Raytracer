/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/04 21:57:16 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	test_hit(t_ray *ray, t_cylinder *c)
{
	if (ray && c)
		return (0);
	return (0);
}

t_cylinder	*inter_cylinders(t_env *e, t_ray *ray)
{
	int		i;

	i = 0;
	while (i < e->scene->n_cylinder)
	{
		if (test_hit(ray, &e->scene->cylinders[i]))
		{
			draw_pixel(e, (t_pixel){ray->origin.x, ray->origin.y,
				e->scene->spheres[i].color});
			return (&e->scene->cylinders[i]);
		}
		++i;
	}
	return (0);
}
