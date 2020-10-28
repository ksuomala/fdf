/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:40:42 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/28 22:24:35 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_string(t_map *fdf)
// {
// 	char	*str;
// 	int		middle;

// 	str = ft_strdup("HELLO WOOO00000000000000000000000000000000000000000000000000RLD");
// 	middle = (ft_strlen(str) / 2);
// 	ft_putnbr(middle);
// 	mlx_string_put(fdf->mlx, fdf->win, WIN_X / 2 - middle,\
// 	WIN_Y / 2, 0xFFFFFF, str);
// }

// void	ft_pixel(t_map *fdf)
// {
// 	int i;

// 	i = 0;
// 	while (i < 666)
// 	{
// 		mlx_pixel_put(fdf->mlx, fdf->win, WIN_X / 2 - 50 + i, WIN_Y / 2, 0xFFFFFF);
// 		i++;
// 	}
// }

// void	ft_image(t_map *fdf)
// {
// 	int		pixel_bits;
// 	int		line_bytes;
// 	int		endian;
// 	int		*buff;

// // Allocates memory for the new image
// 	buff = (int*)mlx_get_data_addr(fdf->img, &pixel_bits, &line_bytes, &endian);
// 	line_bytes /= 4;

// 	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
// }

void	ft_zoom(t_map *fdf, int dir)
{
	if (dir)
	{
		fdf->img->scale += 3;
	}
	else
	{
		fdf->img->scale -= 3;
	}
	if (fdf->img->scale <= 3)
		fdf->img->scale = 1;
}

int		ft_keys(int key, t_map *fdf)
{
	int movement;

	movement = fdf->img->scale / 3;
	if (key == ESC)
	{
		ft_printf("you pressed ESC\n");
		exit (0);
	}
	if (key == A_LEFT)
		fdf->img->move_x -= movement;
	if (key == A_RIGHT)
		fdf->img->move_x += movement;
	if (key == A_UP)
		fdf->img->move_y -= movement;
	if (key == A_DOWN)
		fdf->img->move_y += movement;
	if (key == PLUS)
		ft_zoom(fdf, 1);
	if (key == MINUS)
		ft_zoom(fdf, 0);
	ft_draw_image(fdf);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}

// int ft_key_mod(int key, t_bitmap *img)
// {
// 	ft_printf("You pressed a key!\n");
// 	if (key == A_LEFT)
// 	{
// 		img->move_x -= 1;
// 		ft_printf("you pressed left");
// 	}
// 	if (key == 38)
// 		img->move_y += 1;
// 	if (key == 39)
// 		img->move_x += 1;
// 	if (key == 40)
// 		img->move_y -= 1;
// 	return (0);
// }

void ft_keypress(t_map *fdf)
{
	mlx_hook(fdf->win, 2, 0, &ft_keys, fdf);
	mlx_hook(fdf->win, 17, 0, &ft_exit, fdf);
}

void	ft_init_window(t_map *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, "mlx_window");
	// mlx_hook(fdf->win, 2, 0, &ft_keys, fdf);
	// mlx_hook(fdf->win, 17, 0, &ft_exit, fdf);
	// mlx_hook(fdf->win, 37, 0, &ft_key_mod, fdf);
}