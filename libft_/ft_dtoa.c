/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:03:50 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/16 18:45:58 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_dtoa converts a long double into a character string. Presicion specifies
** the amount of digits added after the decimal point. If roundup is a value
** different from zero, the value will be rounded up with +0.5 method.
** Otherwise the string will be cut after the presicion without rounding up.
*/

static void		ft_half_to_even(long double dec, long double *round)
{
	long long whole;

	whole = (long long)dec;
	dec = dec - whole;
	if (dec < 0.5 || (dec == 0.5 && whole % 2 == 0))
		return ;
	else
		*round += 1;
}

static char		ft_sign(long double dec)
{
	if (1 / dec < 0)
		return ('-');
	else
		return (0);
}

static char		*ft_roundup(char *str, char **whole, int i, char last)
{
	long long convert;

	str[i] = last;
	while (!ft_isdigit(str[i]) && i > 0)
	{
		str[i] = '0';
		str[i - 1] += 1;
		i--;
	}
	if (!ft_isdigit(str[i]) && i == 0)
	{
		str[i] = '0';
		convert = ft_atoi(*whole);
		convert++;
		*whole = ft_replace_ptr(ft_itoa_base(convert, 10), *whole);
	}
	return (str);
}

static char		*ft_decimal(long double dec, char **whole, int presicion,\
int roundup)
{
	int		i;
	char	*ret;
	char	c;

	i = 0;
	if (!(ret = ft_strnew(presicion)))
		return (NULL);
	while (i < presicion - 1)
	{
		dec *= 10;
		c = (char)dec + 48;
		dec -= (int)dec;
		ret[i] = c;
		i++;
	}
	dec *= 10;
	if (roundup)
		ft_half_to_even(dec, &dec);
	c = (char)dec + 48;
	if (roundup)
		ret = ft_roundup(ret, whole, i, c);
	return (ret);
}

char			*ft_dtoa(long double dec, int presicion, int roundup)
{
	char		*pre;
	char		*post;
	char		sign;
	long long	whole;

	sign = ft_sign(dec);
	if (roundup && !presicion && dec != 0)
		ft_half_to_even(dec, &dec);
	whole = (long long)dec;
	pre = ft_itoa_base(whole, 10);
	if (!presicion)
		return (pre);
	dec -= whole;
	post = ft_decimal(dec, &pre, presicion, roundup);
	if (ft_isdigit(post[0]))
	{
		pre = ft_strfjoin(pre, ft_strdup("."));
		if (pre)
			pre = ft_strfjoin(pre, post);
	}
	if (pre[0] != '-' && sign == '-')
		pre = ft_strfjoin(ft_strdup("-"), pre);
	return (pre);
}
