/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 21:04:38 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/13 21:11:47 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fail(t_struct *f)
{
	if (f->spe->convert)
	{
		free(f->spe->convert);
		f->spe->convert = NULL;
	}
	if (f->out)
	{
		free(f->out);
		f->out = NULL;
	}
	if (f->dup)
	{
		free(f->dup);
		f->dup = NULL;
	}
	if (f->spe)
	{
		free(f->spe);
		f->spe = NULL;
	}
	return (-1);
}
