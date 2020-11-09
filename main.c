/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:18:41 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 22:19:20 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(void)
{
	exit(0);
	return (0);
}

void	ft_errors(int val)
{
	if (val == 0)
		ft_printf("Error malloc");
	if (val == 2)
		ft_printf("Error opening file");
	if (val == 3)
		ft_printf("GNL error");
	exit(0);
}

void	ft_init_window(t_map *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, "mlx_window");
	if (!fdf->img)
		fdf->img = ft_memalloc(sizeof(t_bitmap));
	ft_set_scale(fdf, fdf->img);
	fdf->img->zoom = 1;
	ft_zero_to_middle(fdf);
	if (!fdf->img->ptr)
		fdf->img->ptr = mlx_new_image(fdf->mlx, WIN_X, WIN_Y);
	if (!fdf->img->b_map)
		fdf->img->b_map = (int*)mlx_get_data_addr(fdf->img->ptr,\
		&fdf->img->bpp, &fdf->img->size_l, &fdf->img->endian);
	fdf->img->size_l /= 4;
}

int		main(int ac, char **av)
{
	t_map	fdf;

	ft_bzero(&fdf, sizeof(t_map));
	if (ac != 2)
	{
		ft_printf("Usage : ./fdf input_file\n");
		return (0);
	}
	ft_read_map(av, &fdf);
	ft_init_window(&fdf);
	ft_draw_image(&fdf);
	ft_keypress(&fdf);
	mlx_loop(fdf.mlx);
	exit(0);
}
