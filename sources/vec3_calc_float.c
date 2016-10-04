/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:50:07 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/20 17:15:23 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	vector_normalize(t_vec3 *vec)
{
	t_vec3	ret;
	t_vec3	tmp;
	float	len;

	tmp.x /= vec->x * vec->x;
	tmp.y /= vec->y * vec->y;
	tmp.z /= vec->z * vec->z;
	len = sqrtf((tmp.x) + (tmp.y) + (tmp.z));
	ret.x = tmp.x / len;
	ret.y = tmp.y / len;
	ret.z = tmp.z / len;
	return (ret);
}

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
