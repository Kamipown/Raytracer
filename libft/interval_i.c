/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:18:43 by pdelobbe          #+#    #+#             */
/*   Updated: 2016/10/13 21:18:44 by pdelobbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		interval_i(int val, int min, int max)
{
	if (val < min)
		val = min;
	else if (val > max)
		val = max;
	return (val);
}
