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
	ray->origin.x = x;
	ray->origin.y = y;
	ray->origin.z = RAY_START;
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		error(-16, "Unable to create ray.");
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->dir.z = 1;
	return (ray);
}
