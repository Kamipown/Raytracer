/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:33:47 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/28 00:32:46 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		vec_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return (ret);
}

t_vec3		vec_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return (ret);
}

t_vec3		vec_mul(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret;

	ret.x = v1.x * v2.x;
	ret.y = v1.y * v2.y;
	ret.z = v1.z * v2.z;
	return (ret);
}

double		vec_len(t_vec3 v)
{
	double	x;
	double	y;
	double	z;
	double	s;

	x = pow(v.x, 2.0);
	y = pow(v.y, 2.0);
	z = pow(v.z, 2.0);
	s = x + y + z;
	return (s);
}

void		vec_normalize(t_vec3 *v)
{
	double	n;

	n = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	if (n > 0)
	{
		v->x /= n;
		v->y /= n;
		v->z /= n;
	}
}
