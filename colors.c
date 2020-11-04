/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:46:01 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 00:37:14 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color_3(int z, int max, int min)
{
	int color;

	if (z > max * 0.7)
		color = 0xFF0000;
	else if (z > max / 2)
		color = 0xFFFF00;
	else if (z > max / 5)
		color = 0xFF00;
	else if (z > max / 10)
		color = 0x3E418;
	else if (z < min / 2)
		color = 0xFF;
	else if (z < min * 0.7)
		color = 0xcc;
	else if (z < 0)
		color = 0x88;
	else
		color = 0xFFFFFF;
	return (color);
}

int		ft_color_simple(int z, int max)
{
	int color;

	if (z > max * 0.7)
		color = 0xFF0000;
	else
		color = 0xFF00;
	if (z < 0)
		color = 0xFF;
	if (z >= -5 && z <= 5)
		color = (0xFFFFFF);
	return (color);
}

void	ft_toggle_colors(t_map *fdf)
{
	int	y;
	int x;

	if (fdf->img->c == 4)
		fdf->img->c = 0;
	fdf->img->c++;
	y = 0;
	x = 0;
	while (y < fdf->rows)
	{
		while (x < fdf->row_len)
		{
			if (fdf->img->c == 1)
				fdf->map[y][x].color = ft_color_simple((int)fdf->map[y][x].z,\
				fdf->peak_z);
			else if (fdf->img->c == 2)
				fdf->map[y][x].color = ft_color_3((int)fdf->map[y][x].z,\
				fdf->peak_z, fdf->bottom_z);
			else
				fdf->map[y][x].color = 0xFF;
			x++;
		}
		y++;
		x = 0;
	}
}

int		ft_average_rgb(int start, int end)
{
	unsigned char	r;
	unsigned char	b;
	unsigned char	g;
	int				avg;

	r = ((end + start) / 2 >> 16);
	b = (unsigned char)((end + start) / 2);
	g = (unsigned char)((end + start) / 2 >> 8);
	avg = (b) | (g << 8) | (r << 16);
	return (avg);
}
