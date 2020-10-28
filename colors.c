/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:46:01 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/28 22:59:48 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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