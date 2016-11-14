/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:45 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/11/08 22:30:04 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <time.h>

# include "./sdl2/SDL.h"
# include "libft.h"
# include "structs.h"
# include "perlin.h"
# include "prototypes.h"

# define BUFF_SIZE			32

# define MAIN_POS_X			600
# define MAIN_POS_Y			300

# define MIN_SCREEN_W		640
# define MIN_SCREEN_H		480
# define SCREEN_W			800
# define SCREEN_H			600
# define MAX_SCREEN_W		2560
# define MAX_SCREEN_H		1440

# define FOV				30

# define RAY_START			-10000.0
# define RAY_END			20000.0

# define FALSE				0
# define TRUE				1

# define SPHERE				1
# define CYLINDER			2
# define CONE				3
# define PLANE				4
# define MODE_NULL			0
# define MODE_CAMERA		1
# define MODE_CAMERA_ROT	2
# define MODE_SELECT		3
# define MODE_SELECT_ROT	4
# define MODE_TEXTURES		5
# define MODE_BUMPMAPPING	6

# define MOVE_SPEED			50
# define ROT_SPEED			10

# define POINT_LIGHT		0
# define DIRECTIONAL_LIGHT	1
# define SPOT_LIGHT			2

# define BRIGHTNESS			40

#endif
