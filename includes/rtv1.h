/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:45 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/04/18 19:46:46 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# include "libft.h"
# include "shapes.h"

# define BUFF_SIZE		32

# define MIN_SCREEN_W	640
# define MIN_SCREEN_H	480
# define SCREEN_W		800
# define SCREEN_H		600
# define MAX_SCREEN_W	2560
# define MAX_SCREEN_H	1440

# define ESCAPE			53

# define RAY_START		-1000.0f
# define RAY_END		1000.0f

typedef struct		s_scene
{
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

typedef struct		s_img
{
	void			*data;
	int				bpp;
	int				size;
	int				endian;
	char			*buf;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_scene			*scene;
}					t_env;

void				init(t_env *e, char *filename);

void				parse_scene(t_scene *s, char *filename);
char				*read_file(char *filename);
char				*read_data(char *data, char *request);
int					read_int_data(char *data, char *request);
int					read_color_data(char *data, char *request);
char				*construct_request_int(char *request, int n);

void				fill_screen_data(t_scene *s, char *data);
void				fill_counts_data(t_scene *s, char *data);
void				fill_lights_data(t_scene *s, char *data);
void				fill_spheres_data(t_scene *s, char *data);

void				fill_cylinders_data(t_scene *s, char *data);
void				fill_cones_data(t_scene *s, char *data);
void				fill_planes_data(t_scene *s, char *data);

int					expose_hook(t_env *e);
int					key_hook(int k, t_env *e);

void				draw_image(t_env *e);
void				draw_pixel(t_env *e, t_pixel p);

void				raytrace(t_env *e);

void				update_ray(t_ray *ray, int x, int y);
t_ray				*init_ray(void);

void				error(int n, char *mes);

#endif
