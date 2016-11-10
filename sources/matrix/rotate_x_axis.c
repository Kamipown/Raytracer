/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 03:00:11 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/04 03:00:18 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_left(t_vec3 *v)
{
	v->x += ROT_SPEED;
	if (v->x >= 360)
		v->x -= 360;
}

void	rotate_normal_left(t_vec3 *v)
{
	double	t;

	t = v->x;
	v->x = v->x * cos(ROT_SPEED * M_PI / 180)
			+ v->z * sin(ROT_SPEED * M_PI / 180);
	v->z = t * -(sin(ROT_SPEED * M_PI / 180))
			+ v->z * cos(ROT_SPEED * M_PI / 180);
}

void	rotate_right(t_vec3 *v)
{
	v->x -= ROT_SPEED;
	if (v->x < 0)
		v->x += 360;
}

void	rotate_normal_right(t_vec3 *v)
{
	double	t;

	t = v->x;
	v->x = v->x * cos(-ROT_SPEED * M_PI / 180)
			+ v->z * sin(-ROT_SPEED * M_PI / 180);
	v->z = t * -(sin(-ROT_SPEED * M_PI / 180))
			+ v->z * cos(-ROT_SPEED * M_PI / 180);
}
