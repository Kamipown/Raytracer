/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromon <gromon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 23:50:54 by gromon            #+#    #+#             */
/*   Updated: 2016/10/27 22:21:48 by gromon           ###   ########.fr       */
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
double		    	read_double_data(char *data, char *request);
int					read_color_data(char *data, char *request);
char				*construct_request_int(char *request, int n);
int					data_get_i_constructed(char *data, char *request, int i);
int					data_get_d_constructed(char *data, char *request, int i);

void                load_textures(t_env *e);
void                free_textures(t_env *e);

void				fill_screen_data(t_scene *s, char *data);
void				fill_camera_data(t_scene *s, char *data);
int					*fill_counts_data(t_scene *s, char *data);

void				fill_lights_data(t_scene *s, char *data);

void				fill_spheres_data(t_scene *s, char *data, int counts[4]);
void				fill_cylinders_data(t_scene *s, char *data, int counts[4]);
void				fill_cones_data(t_scene *s, char *data, int counts[4]);
void				fill_planes_data(t_scene *s, char *data, int counts[4]);
void		        fill_screen_data(t_scene *s, char *data);
void		        fill_light_data(t_scene *s, char *data);

void				loop(t_env *e);

void				init_inputs(t_inputs *inputs);
void				get_inputs(t_env *e);
void				get_inputs_keys(t_env *e, t_bool pressed);
void				get_inputs_mouse(t_env *e);

void				switch_mode(t_env *e);
void				move(t_env *e);

void				key_hook(t_env *e);
void				mouse_hook(t_env *e);

void				toggle_fullscreen(t_env *e);

void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_forward(t_env *e);
void				move_backward(t_env *e);

void				draw(t_env *e);
void				draw_pixel(t_env *e, t_pixel p);

void				raytrace(t_env *e);

void				create_ray(t_scene *scene, t_vec3 to);

t_intersection		*throw_ray(t_env *e, t_ray *ray, int flag);

void				intersect_objects(t_env *e, t_ray *ray, t_intersection *inter, int flag);
t_bool				inter_spheres(t_ray *ray, t_obj *s, double *t);
t_bool				inter_cylinders(t_ray *ray, t_obj *c, double *t);
t_bool				inter_cones(t_ray *ray, t_obj *c, double *t);
t_bool				inter_planes(t_ray *ray, t_obj *p, double *t);
t_bool				solve_quadratic(t_equation e, double *t);
double			    calc_dist(t_vec3 *v1, t_vec3 *v2);
t_vec3			    get_normal(t_vec3 *pos, t_obj *obj, t_ray *ray);
t_color	            get_global_illuminated_color(t_color *c);
void			    flour_color(t_color *color);

void				process_lighting(t_env *e, t_ray *ray, t_intersection *inter, t_color *color);

t_vec3				vec_add(t_vec3 v1, t_vec3 v2);
t_vec3				vec_sub(t_vec3 v1, t_vec3 v2);
t_vec3				vec_mul(t_vec3 v1, t_vec3 v2);
t_vec3				vec_div(t_vec3 v1, t_vec3 v2);
void				vec_normalize(t_vec3 *v);
double				vec_add_to_d(t_vec3 v1, t_vec3 v2);
double				vec_sub_to_d(t_vec3 v1, t_vec3 v2);
double				vec_mul_to_d(t_vec3 v1, t_vec3 v2);
t_vec3				vec_mul_d(t_vec3 v, double d);

void				error(int n, char *mes);

void				debug_print_screen(t_size *size);
void				debug_print_camera(t_cam *cam);
void				debug_print_counts(t_scene *s);
void				debug_print_lights(t_scene *s);
void				debug_print_spheres(t_scene *s);
void				debug_print_planes(t_scene *s);
void				debug_print_cylinders(t_scene *s);
void				debug_print_cones(t_scene *s);

void        write_informations(t_env *e);

void		    take_screenshoot(t_env *e);

#endif
