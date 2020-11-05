/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:28:02 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 16:08:00 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_sign(t_struct *f)
{
	long long nb;

	nb = f->spe->data;
	if (nb < 0)
		f->spe->sign = '-';
	else if (f->spe->plus && nb >= 0)
		f->spe->sign = '+';
	else if (f->spe->space && !f->spe->plus && nb >= 0)
		f->spe->sign = ' ';
	else
		f->spe->sign = '\0';
	return (f->spe->sign);
}

int				ft_left(t_struct *f)
{
	if (f->spe->zero && !f->spe->minus && !f->spe->p_is)
	{
		if (f->spe->sign)
		{
			if (!(ft_chrtobuf(f, f->spe->sign, 1)))
				return (0);
			f->spe->sign = '\0';
		}
		if (!(ft_chrtobuf(f, '0', (f->spe->width - f->spe->slen))))
			return (0);
	}
	else
	{
		if (!(ft_chrtobuf(f, ' ', (f->spe->width - f->spe->slen))))
			return (0);
	}
	return (1);
}

char			*ft_removesign(char **convert)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*convert);
	tmp = ft_strsub(*convert, 1, len - 1);
	free(*convert);
	return (tmp);
}

int				ft_conversion_to_buf(t_struct *f)
{
	if (f->spe->width > f->spe->slen && !f->spe->minus)
		if (!(ft_left(f)))
			return (0);
	if (f->spe->sign)
		if (!(ft_chrtobuf(f, f->spe->sign, 1)))
			return (0);
	if (!(ft_strtobuf(f)))
		return (0);
	if (f->spe->minus)
		if (!(ft_chrtobuf(f, ' ', (f->spe->width - f->spe->slen))))
			return (0);
	return (1);
}

int				ft_d(t_struct *f)
{
	f->spe->slen = 0;
	ft_argcast(f);
	ft_sign(f);
	if (f->spe->sign)
		f->spe->slen++;
	if (f->spe->data < 0)
		f->spe->data *= -1;
	if (!f->spe->data && f->spe->p_is && !f->spe->p_len)
		f->spe->convert = ft_strdup("");
	else
	{
		f->spe->convert = ft_itoa_base(f->spe->data, 10);
		if (f->spe->convert[0] == '-')
			f->spe->convert = ft_removesign(&f->spe->convert);
	}
	if (!f->spe->convert)
		return (0);
	if (f->spe->p_is)
		f->spe->convert = ft_add_presicion(f);
	f->spe->slen += (int)ft_strlen(f->spe->convert);
	if (!ft_conversion_to_buf(f))
		return (0);
	return (1);
}
