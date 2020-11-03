/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:18:41 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/02 22:25:58 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		main(int ac, char **av)
{
	t_map	fdf;

	ft_bzero(&fdf, sizeof(t_map));
	if (ac != 2)
	{
		ft_printf("Usage : ./fillit input_file\n");
		return (0);
	}
	ft_read_map(av, &fdf);
	ft_init_window(&fdf);
	ft_draw_image(&fdf);
	ft_keypress(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
