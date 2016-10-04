/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:45 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/09/21 13:50:52 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# include "./sdl2/SDL.h"
# include "libft.h"
# include "structs.h"
# include "shapes.h"

# define BUFF_SIZE		32

# define MIN_SCREEN_W	640
# define MIN_SCREEN_H	480
# define SCREEN_W		800
# define SCREEN_H		600
# define MAX_SCREEN_W	2560
# define MAX_SCREEN_H	1440

# define ESCAPE			53

# define FOV			30

# define RAY_START		-10000.0f
# define RAY_END		20000.0f

# define FALSE			0
# define TRUE			1

# define SPHERE			0
# define CYLINDER		1
# define CONE			2
# define PLANE			3

typedef unsigned int	t_bool;

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
}					t_scene;

typedef struct		s_inputs
{
	t_bool			escape;
	t_bool			key_f;
	t_bool			mouse_left;
	int				mouse_x;
	int				mouse_y;
}					t_inputs;

typedef struct		s_options
{
	t_bool			fullscreen;
	t_bool			quit;
	t_bool			need_redraw;
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

void				init(t_env *e, char *filename);
void				quit(t_env *e);

void				parse_scene(t_scene *s, char *filename);
char				*read_file(char *filename);
char				*read_data(char *data, char *request);
int					read_int_data(char *data, char *request);
int					read_color_data(char *data, char *request);
char				*construct_request_int(char *request, int n);

void				fill_screen_data(t_scene *s, char *data);
void				fill_counts_data(t_scene *s, char *data);
void				fill_camera_data(t_scene *s, char *data);
void				fill_lights_data(t_scene *s, char *data);
void				fill_spheres_data(t_scene *s, char *data);

void				fill_cylinders_data(t_scene *s, char *data);
void				fill_cones_data(t_scene *s, char *data);
void				fill_planes_data(t_scene *s, char *data);

void				loop(t_env *e);

void				get_inputs(t_env *e);

void				key_hook(t_env *e);
void				mouse_hook(t_env *e);

void				draw(t_env *e);
void				draw_pixel(t_env *e, t_pixel p);

void				raytrace(t_env *e);

t_ray				*create_ray(t_vec3 *from, t_vec3 to);
void				throw_ray(t_env *e, t_ray *ray, int x, int y);

t_vec3				vec_add(t_vec3 *v1, t_vec3 *v2);
t_vec3				vec_sub(t_vec3 *v1, t_vec3 *v2);
t_vec3				vec_mul(t_vec3 *v1, t_vec3 *v2);
t_vec3				vec_div(t_vec3 *v1, t_vec3 *v2);
void				vec_normalize(t_vec3 *v);
t_vec3				vector_normalize(t_vec3 *vec);
float				vec_add_to_f(t_vec3 *v1, t_vec3 *v2);
float				vec_sub_to_f(t_vec3 *v1, t_vec3 *v2);
float				vec_mul_to_f(t_vec3 *v1, t_vec3 *v2);
float				vec_div_to_f(t_vec3 *v1, t_vec3 *v2);

int					inter_spheres(t_env *e, t_ray *ray, int x, int y);
int					inter_cylinders(t_env *e, t_ray *ray);
int					inter_cones(t_env *e, t_ray *ray);
int					inter_planes(t_env *e, t_ray *ray);

void				error(int n, char *mes);

#endif
