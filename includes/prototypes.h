/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:21:09 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/04 22:21:11 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

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
