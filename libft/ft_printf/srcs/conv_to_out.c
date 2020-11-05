/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:48:49 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/14 17:42:53 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_s_to_buf(t_struct *f)
{
	if (f->spe->width > f->spe->slen && !f->spe->minus)
	{
		if (f->spe->zero)
		{
			if (!ft_chrtobuf(f, '0', (f->spe->width - f->spe->slen)))
				return (NULL);
		}
		else if (!ft_chrtobuf(f, ' ', (f->spe->width - f->spe->slen)))
			return (NULL);
	}
	if (f->spe->p_is && (int)ft_strlen(f->spe->convert) > f->spe->p_len)
		f->spe->convert[f->spe->p_len] = '\0';
	if (!ft_strtobuf(f))
		return (NULL);
	if (f->spe->width > f->spe->slen && f->spe->minus)
	{
		if (!ft_chrtobuf(f, ' ', (f->spe->width - f->spe->slen)))
			return (NULL);
	}
	return (f->spe->convert);
}

char	*ft_nb_to_buf(t_struct *f, int l)
{
	if ((l > 0 && !f->spe->minus && !f->spe->zero) ||\
	(f->spe->zero && f->spe->p_is && l > 0 &&\
	!f->spe->minus))
	{
		if (!(ft_chrtobuf(f, ' ', l)))
			return (NULL);
	}
	if (!(ft_strtobuf(f)))
		return (NULL);
	if (l > 0 && f->spe->minus)
	{
		if (!(ft_chrtobuf(f, ' ', l)))
			return (NULL);
	}
	return (f->spe->convert);
}

char	*ft_fl_to_buf(t_struct *f, int l)
{
	if (f->spe->sign && !f->spe->zero)
		if (!(f->spe->convert = ft_chrnstr_pre(&f->spe->convert,\
		f->spe->sign, 1)))
			return (NULL);
	if (l > 0 && !f->spe->minus && !f->spe->zero)
		f->spe->convert = ft_chrnstr_pre(&f->spe->convert, ' ', l);
	else if (l > 0 && !f->spe->minus && f->spe->zero)
		f->spe->convert = ft_chrnstr_pre(&f->spe->convert, '0', l);
	if (!f->spe->convert)
		return (NULL);
	if (f->spe->sign && f->spe->zero)
		if (!(f->spe->convert = ft_chrnstr_pre(&f->spe->convert,\
		f->spe->sign, 1)))
			return (NULL);
	if (f->spe->p_is && !f->spe->p_len && f->spe->hash && (f->spe->type == 'f'\
	|| f->spe->g == 'f') && !ft_strchr(f->spe->convert, '.'))
		if (!(f->spe->convert = ft_chrnstr_post(&f->spe->convert, '.', 1)))
			return (0);
	if (l > 0 && f->spe->minus)
		f->spe->convert = ft_chrnstr_post(&f->spe->convert, ' ', l);
	return (f->spe->convert);
}
