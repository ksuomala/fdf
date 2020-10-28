/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:46:01 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/29 00:26:59 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//NewColor = sqrt((R1^2+R2^2)/2),sqrt((G1^2+G2^2)/2),sqrt((B1^2+B2^2)/2)

int ft_red(int start, int end)
{
	char *asc;

	asc = ft_itoa(start);
	asc[3] = '\0';
	start = ft_atoi(asc);
	free(asc);
	asc = ft_itoa(end);
	asc[3] = '\0';
	end = ft_atoi(asc);
//	return (sqrt(((start * start) + (end * end)) / 2) * 100000);
	return (((start + end) / 2) * 1000000);
}

int ft_green(int start, int end)
{
	char *asc;

	asc = ft_itoa(start);
	asc[6] = '\0';
	start = ft_atoi(asc + 3);
	free(asc);
	asc = ft_itoa(end);
	asc[6] = '\0';
	end = ft_atoi(asc + 3);
//	return (sqrt(((start * start) + (end * end)) / 2) * 1000);
	return (((start + end) / 2) * 1000);
}

int ft_blue(int start, int end)
{
	char *asc;

	asc = ft_itoa(start);
	asc[3] = '\0';
	start = ft_atoi(asc);
	free(asc);
	asc = ft_itoa(end);
	asc[3] = '\0';
	end = ft_atoi(asc);
//	return (sqrt(((start * start) + (end * end)) / 2));
	return (((start + end) / 2));
}
int		ft_average_rgb(int start, int end)
{
	int red;
	int green;
	int blue;

	red = ft_red(start, end);
	green = ft_green(start, end);
	blue = ft_blue(start, end);
	ft_printf("start|end = |%d|%d|, red = |%d|,green = |%d| blue = |%d| \n", start, end, red, green, blue);
	return (red + green + blue);
}

int		ft_color(int height)
{
	int color;

	if (height < 5 && height > -5)
		color = 0xFFFFFF;
	else if (height > 4 && height <= 10)
		color = 0xFF0000;
	else if (height < -5)
		color = 0x0000FF;
	else
		color = 0x00FF00;
	return (color);
}