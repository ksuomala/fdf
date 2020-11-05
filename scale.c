/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:16:59 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 20:05:32 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_multiply_scale(t_pt *start, t_pt *end, int scale)
{
	start->x *= scale;
	start->y *= scale;
	end->y *= scale;
	end->x *= scale;
	start->z *= scale;
	end->z *= scale;
}

void	ft_set_scale(t_map *fdf, t_bitmap *map)
{
	if (!map->height)
	{
		map->height = fdf->row_count;
		map->width = fdf->row_len_max;
	}
	map->scale = 3;
	while (map->height * map->scale * 2 <= WIN_Y && map->width\
	* map->scale * 2 <= WIN_X)
		map->scale += 3;
}

void	ft_mid(t_map *fdf)
{
	fdf->img->mid_y = WIN_Y / 2;
	fdf->img->mid_x = WIN_X / 2;
}

void	ft_set_height(t_map *fdf)
{
	if (!fdf->img->pro)
	{
		fdf->img->width = fdf->row_len_max;
		fdf->img->height = fdf->row_count;
	}
	if (fdf->img->pro == 1)
	{
		fdf->img->width = fdf->row_len_max * cos(RAD_ISO)\
		+ fdf->row_count * cos(RAD_ISO);
		fdf->img->height = fdf->row_len_max * sin(RAD_ISO)\
		+ fdf->row_count * sin(RAD_ISO);
	}
	if (fdf->img->pro == 2)
	{
		fdf->img->width = fdf->row_len_max * cos(RAD_MIL) +\
		fdf->row_count * sin(RAD_MIL);
		fdf->img->height = fdf->row_len_max * sin(RAD_MIL) +\
		fdf->row_count * sin(RAD_MIL);
	}
}
