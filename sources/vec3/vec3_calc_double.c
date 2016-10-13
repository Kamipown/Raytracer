/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:50:07 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/07 15:20:43 by gromon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	vec_add_to_d(t_vec3 v1, t_vec3 v2)
{
	return ((v1.x + v2.x) + (v1.y + v2.y) + (v1.z + v2.z));
}

double	vec_sub_to_d(t_vec3 v1, t_vec3 v2)
{
	return ((v1.x - v2.x) + (v1.y - v2.y) + (v1.z - v2.z));
}

double	vec_mul_to_d(t_vec3 v1, t_vec3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vec3	vec_mul_d(t_vec3 v, double d)
{
	t_vec3	ret;

	ret.x = v.x * d;
	ret.y = v.y * d;
	ret.z = v.z * d;
	return (ret);
}
