/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 03:00:39 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/04 03:00:41 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_forward(t_vec3 *v)
{
	v->z += ROT_SPEED;
	if (v->z >= 360)
		v->z -= 360;
}

void	rotate_normal_forward(t_vec3 *v)
{
	double	t;

	t = v->x;
	v->x = v->x * cos(ROT_SPEED * M_PI / 180)
			+ v->y * -(sin(ROT_SPEED * M_PI / 180));
	v->y = t * sin(ROT_SPEED * M_PI / 180)
			+ v->y * cos(ROT_SPEED * M_PI / 180);
}

void	rotate_backward(t_vec3 *v)
{
	v->z -= ROT_SPEED;
	if (v->z < 0)
		v->z += 360;
}

void	rotate_normal_backward(t_vec3 *v)
{
	double	t;

	t = v->x;
	v->x = v->x * cos(-ROT_SPEED * M_PI / 180)
			+ v->y * -(sin(-ROT_SPEED * M_PI / 180));
	v->y = t * sin(-ROT_SPEED * M_PI / 180)
			+ v->y * cos(-ROT_SPEED * M_PI / 180);
}
