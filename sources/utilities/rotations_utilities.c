/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:46:03 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/10 03:46:05 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	vector_rotate_x(t_vec3 *v, double ang)
{
	double		tmp_y;
	double		tmp_x;

	tmp_y = v->y;
	tmp_x = v->z;
	v->y = tmp_y * cos(ang) - tmp_x * sin(ang);
	v->z = tmp_y * sin(ang) + tmp_x * cos(ang);
}

void	vector_rotate_y(t_vec3 *v, double ang)
{
	double		temp_x;
	double		tmp_x;

	temp_x = v->x;
	tmp_x = v->z;
	v->z = tmp_x * cos(ang) - temp_x * sin(ang);
	v->x = tmp_x * sin(ang) + temp_x * cos(ang);
}

void	vector_rotate_z(t_vec3 *v, double ang)
{
	double		temp_x;
	double		tmp_y;

	temp_x = v->x;
	tmp_y = v->y;
	v->x = temp_x * cos(ang) - tmp_y * sin(ang);
	v->y = temp_x * sin(ang) + tmp_y * cos(ang);
}
