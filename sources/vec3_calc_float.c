/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:50:07 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/15 16:50:08 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	vec_add_to_f(t_vec3 *v1, t_vec3 *v2)
{
	return ((v1->x + v2->x) + (v1->y + v2->y) + (v1->z + v2->z));
}

float	vec_sub_to_f(t_vec3 *v1, t_vec3 *v2)
{
	return ((v1->x - v2->x) + (v1->y - v2->y) + (v1->z - v2->z));
}

float	vec_mul_to_f(t_vec3 *v1, t_vec3 *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

float	vec_div_to_f(t_vec3 *v1, t_vec3 *v2)
{
	return ((v1->x / v2->x) + (v1->y / v2->y) + (v1->z / v2->z));
}
