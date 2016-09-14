/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:52:44 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/05 16:52:46 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	update_ray(t_ray *ray, int x, int y)
{
	ray->end.x = (ray->end.z - ray->start.z) / 1000 * x;
	ray->end.y = (ray->end.z - ray->start.z) / 1000 * y;
	ray->end.z = RAY_END;
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		error(-16, "Unable to create ray.");
	ray->start.x = 0;
	ray->start.y = 0;
	ray->start.z = RAY_START;
	return (ray);
}
