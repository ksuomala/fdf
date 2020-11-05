/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:16:59 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 02:06:56 by ksuomala         ###   ########.fr       */
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
		map->height = fdf->rows;
		map->width = fdf->row_len;
	}
	map->scale = 3;
	while (map->height * map->scale * 2 <= WIN_Y && map->width\
	* map->scale * 2 <= WIN_X)
		map->scale += 3;
	ft_printf("scale = %d", map->scale);
}

void	ft_mid(t_map *fdf)
{
	fdf->end_x = fdf->row_len - fdf->start_x;
	fdf->end_y = fdf->rows - fdf->start_y;
	fdf->img->mid_y = WIN_Y / 2;
	fdf->img->mid_x = WIN_X / 2;
}

void	ft_set_height(t_map *fdf)
{
	if (!fdf->img->pro)
	{
		fdf->img->width = fdf->row_len;
		fdf->img->height = fdf->rows;
	}
	if (fdf->img->pro == 1)
	{
		fdf->img->width = fdf->row_len * cos(RAD_ISO)\
		+ fdf->rows * cos(RAD_ISO);
		fdf->img->height = fdf->row_len * sin(RAD_ISO)\
		+ fdf->rows * sin(RAD_ISO);
	}
	if (fdf->img->pro == 2)
	{
		fdf->img->width = fdf->row_len * cos(RAD_MIL) +\
		fdf->rows * sin(RAD_MIL);
		fdf->img->height = fdf->row_len * sin(RAD_MIL) +\
		fdf->rows * sin(RAD_MIL);
	}
}
