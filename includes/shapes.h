/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:49:39 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/21 13:50:56 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

typedef struct		s_light
{
	t_vec3			pos;
	int				color;
	int				intensity;
}					t_light;

typedef struct		s_sphere
{
	t_vec3			pos;
	int				color;
	int				radius;
}					t_sphere;

typedef struct		s_cylinder
{
	t_vec3			pos;
	t_vec3			rot;
	int				height;
	int				radius;
}					t_cylinder;

typedef struct		s_cone
{
	t_vec3			pos;
	t_vec3			rot;
	int				height;
}					t_cone;

typedef struct		s_plane
{
	t_vec3			pos;
	t_vec3			rot;
	int				width;
	int				height;
	int				color;
}					t_plane;

#endif
