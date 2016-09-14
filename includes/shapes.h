/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:49:39 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/27 16:49:40 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				color;
}					t_pixel;

typedef struct		s_size
{
	int				w;
	int				h;
	int				s_x;
	int				s_y;
	int				e_x;
	int				e_y;
}					t_size;

typedef struct		s_vec3
{
	int				x;
	int				y;
	int				z;
}					t_vec3;

typedef struct		s_ray
{
	t_vec3			start;
	t_vec3			end;
}					t_ray;

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
}					t_plane;

#endif
