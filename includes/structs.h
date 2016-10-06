/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:01:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 17:44:00 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned int	t_bool;

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

typedef struct		s_intersection
{
	t_sphere		*sphere;
	t_cylinder		*cylinder;
	t_cone			*cone;
	t_plane			*plane;
	//int				z;
	int				shape_type;
}					t_intersection;

typedef struct		s_scene
{
	t_cam			*cam;
	t_light			*lights;
	t_sphere		*spheres;
	t_cylinder		*cylinders;
	t_cone			*cones;
	t_plane			*planes;
	int				n_light;
	int				n_sphere;
	int				n_cylinder;
	int				n_cone;
	int				n_plane;
	t_size			size;
	t_intersection	*selected;
}					t_scene;

typedef struct		s_inputs
{
	t_bool			escape;
	t_bool			key_1;
	t_bool			key_2;
	t_bool			key_f;
	t_bool			key_left;
	t_bool			key_right;
	t_bool			key_up;
	t_bool			key_down;
	t_bool			key_forward;
	t_bool			key_backward;
	t_bool			mouse_left;
	int				mouse_x;
	int				mouse_y;
}					t_inputs;

typedef struct		s_options
{
	t_bool			fullscreen;
	t_bool			quit;
	t_bool			need_redraw;
	t_bool			mode;
}					t_options;

typedef struct		s_env
{
	t_scene			*scene;
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	t_inputs		inputs;
	t_options		options;
}					t_env;

#endif
