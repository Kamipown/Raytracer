/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 03:00:27 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/04 03:00:29 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_up(t_vec3 *v)
{
	v->y += ROT_SPEED;
	if (v->y >= 360)
		v->y -= 360;
}

void	rotate_normal_up(t_vec3 *v)
{
	double	t;

	t = v->y;
	v->y = v->y * cos(ROT_SPEED * M_PI / 180)
			+ v->z * -(sin(ROT_SPEED * M_PI / 180));
	v->z = t * sin(ROT_SPEED * M_PI / 180)
			+ v->z * cos(ROT_SPEED * M_PI / 180);
}

void	rotate_down(t_vec3 *v)
{
	v->y -= ROT_SPEED;
	if (v->y < 0)
		v->y += 360;
}

void	rotate_normal_down(t_vec3 *v)
{
	double	t;

	t = v->y;
	v->y = v->y * cos(-ROT_SPEED * M_PI / 180)
			+ v->z * -(sin(-ROT_SPEED * M_PI / 180));
	v->z = t * sin(-ROT_SPEED * M_PI / 180)
			+ v->z * cos(-ROT_SPEED * M_PI / 180);
}
