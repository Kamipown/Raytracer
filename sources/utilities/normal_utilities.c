/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 03:59:51 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/12 04:35:45 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vec3	sphere_normal(t_vec3 *pos, t_obj *obj)
{
	t_vec3		normal;

	normal = vec_sub(*pos, obj->pos);
	vec_normalize(&normal);
	return (normal);
}

static t_vec3	cylinder_normal(t_vec3 *pos, t_obj *obj)
{
	t_vec3		normal;

	normal = vec_sub(*pos, obj->pos);
	vec_rotate(&normal, obj->rot);
	normal.y = 0;
	vec_unrotate(&normal, obj->rot);
	vec_normalize(&normal);
	return (normal);
}

static t_vec3	cone_normal(t_vec3 *pos, t_obj *obj)
{
	t_vec3		normal;

	normal = vec_sub(*pos, obj->pos);
	vec_rotate(&normal, obj->rot);
	normal.y *= -1;
	vec_unrotate(&normal, obj->rot);
	vec_normalize(&normal);
	return (normal);
}

static t_vec3	plane_normal(t_obj *obj)
{
	t_vec3		normal;

	normal = (t_vec3){obj->rot.x, obj->rot.y, obj->rot.z};
	vec_normalize(&normal);
	return (normal);
}

t_vec3			get_normal(t_vec3 *pos, t_obj *obj)
{
	if (obj->type == SPHERE)
		return (sphere_normal(pos, obj));
	else if (obj->type == CYLINDER)
		return (cylinder_normal(pos, obj));
	else if (obj->type == CONE)
		return (cone_normal(pos, obj));
	else if (obj->type == PLANE)
		return (plane_normal(obj));
	return ((t_vec3){0, 0, 0});
}
