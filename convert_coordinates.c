/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:47:40 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 00:49:38 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pt	ft_rotate_z(float x, float y, float angle)
{
	t_pt	new;

	new.x = x * cos(angle) - y * sin(angle);
	new.y = x * sin(angle) + y * cos(angle);
	return (new);
}

void	ft_multiply_zoom(t_pt *s, t_pt *e, float zoom)
{
	s->x *= zoom;
	s->y *= zoom;
	s->z *= zoom;
	e->x *= zoom;
	e->y *= zoom;
	e->z *= zoom;
}

t_pt	ft_paral_rot(t_pt *p, t_bitmap *img)
{
	t_pt temp;

	temp.x = p->x;
	temp.y = p->y;
	temp.z = p->z;
	temp = ft_rotate_z(temp.x, temp.y, img->rot_z);
	temp.color = p->color;
	return (temp);
}

t_pt	ft_convert_xy(t_pt *p, float amplitude, t_bitmap *img, double rad)
{
	t_pt temp;

	temp.x = p->x;
	temp.y = p->y;
	temp.z = p->z;
	temp = ft_rotate_z(temp.x, temp.y, img->rot_z);
	temp.color = p->color;
	if (p->z)
		temp.z = p->z * (1.0 + amplitude);
	else
		temp.z = p->z;
	temp.x = (temp.x - temp.y) * cos(rad);
	temp.y = (temp.x + temp.y) * sin(rad) - temp.z;
	return (temp);
}
