/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:49:33 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 17:38:58 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				ft_shorter_spe(long double *nb, int exp, int pre)
{
	char	*roundup;
	int		conv;

	if (!(roundup = ft_dtoa(*nb, pre, 1)))
		return (0);
	conv = ft_atoi(roundup);
	free(roundup);
	if (conv >= 10)
		exp++;
	if (exp < -4)
		return ('e');
	if ((exp >= pre && pre) || (exp >= 1 && !pre))
		return ('e');
	else
		return ('f');
}

static long double	ft_exponent(int *exp, long double temp)
{
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		*exp += 1;
	}
	while ((temp < 1 && temp > 0) || (temp > -1 && temp < 0))
	{
		temp *= 10;
		*exp -= 1;
	}
	return (temp);
}

int					ft_e(t_struct *f, long double *nb)
{
	long double temp;
	int			presicion;

	if (f->spe->p_is && f->spe->p_len)
		presicion = f->spe->p_len;
	else if (f->spe->p_is && !f->spe->p_len)
		presicion = 0;
	else
		presicion = 6;
	if (f->spe->type == 'g' && presicion == 1 && (*nb >= 1 || *nb <= -1))
		presicion--;
	temp = ft_exponent(&f->spe->exponent, *nb);
	if (f->spe->g)
		if (!(f->spe->g = ft_shorter_spe(&temp, f->spe->exponent, presicion)))
			return (0);
	if (f->spe->g == 'e' || f->spe->type == 'e')
		*nb = temp;
	return (1);
}
