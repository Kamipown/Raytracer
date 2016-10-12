/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:57:15 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/07 16:20:10 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	test_hit(t_ray *ray, t_cylinder *c, double *z)
{
	t_bool	ret;

	ret = FALSE;
	
	return (ret));
}

void		inter_cylinders(t_env *e, t_ray *ray, t_intersection *inter)
{
	int		i;
	double	z;

	i = 0;
	while (i < e->scene->n_cylinder)
	{
		if (test_hit(ray, &e->scene->cylinders[i], &z))
		{
			draw_pixel(e, (t_pixel){x, y, e->scene->spheres[i].color});
	// 		return (&e->scene->cylinders[i]);
			if (z < RAY_END)
			{
				if (!inter->sphere)
				{
					inter->sphere = &e->scene->spheres[i];
					inter->z_sphere = z;
				}
				else
				{
					if (z < inter->z_sphere)
					{
						inter->sphere = &e->scene->spheres[i];
						inter->z_sphere = z;
					}
				}
			}
		}
		++i;
	}
	return (0);
}
