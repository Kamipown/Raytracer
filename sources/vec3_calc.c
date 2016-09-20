/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:33:47 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/15 16:33:48 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3 		vector_normalize(t_vec3 *vec)
{
	float len;

	len = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));	
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}


t_vec3		vec_add(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	ret;

	ret.x = v1->x + v2->x;
	ret.y = v1->y + v2->y;
	ret.z = v1->z + v2->z;
	return (ret);
}

t_vec3		vec_sub(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	ret;

	ret.x = v1->x - v2->x;
	ret.y = v1->y - v2->y;
	ret.z = v1->z - v2->z;
	return (ret);
}

t_vec3		vec_mul(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	ret;

	ret.x = v1->x * v2->x;
	ret.y = v1->y * v2->y;
	ret.z = v1->z * v2->z;
	return (ret);
}

t_vec3		vec_div(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	ret;

	ret.x = v1->x / v2->x;
	ret.y = v1->y / v2->y;
	ret.z = v1->z / v2->z;
	return (ret);
}
