/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:46:45 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/05 15:46:01 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h> // TO DELETE

# include "./sdl2/SDL.h"
# include "libft.h"
# include "structs.h"
# include "prototypes.h"

# define BUFF_SIZE		32

# define MIN_SCREEN_W	640
# define MIN_SCREEN_H	480
# define SCREEN_W		800
# define SCREEN_H		600
# define MAX_SCREEN_W	2560
# define MAX_SCREEN_H	1440

# define ESCAPE			53

# define FOV			30

# define RAY_START		-10000.0
# define RAY_END		20000.0

# define FALSE			0
# define TRUE			1

# define SPHERE			1
# define CYLINDER		2
# define CONE			3
# define PLANE			4

# define MODE_NULL      0
# define MODE_CAMERA    1
# define MODE_SELECT    2

# define MOVE_SPEED		20

#endif
