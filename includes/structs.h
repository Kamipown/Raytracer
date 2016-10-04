/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:01:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/04 22:01:45 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

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
}					t_size;

typedef struct		s_ray
{
	t_vec3			origin;
	t_vec3			dir;
}					t_ray;

typedef struct		s_cam
{
	t_vec3			pos;
	int				fov;
	float			focal_dist;
}					t_cam;

#endif
