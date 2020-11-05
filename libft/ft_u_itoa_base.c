/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:14:20 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/12 21:22:00 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(unsigned long long *nb, int base)
{
	int					i;
	unsigned long long	n;

	i = 1;
	n = *nb;
	while (n >= (unsigned long long)base)
	{
		n /= base;
		i++;
	}
	return (i);
}

static int	ft_check(unsigned long long *nb, int base, char str[20])
{
	int		numlen;

	numlen = ft_numlen(nb, base);
	str[numlen] = '\0';
	return (numlen);
}

char		*ft_u_itoa_base(unsigned long long nb, int base)
{
	int			numlen;
	long long	mod;
	char		str[21];
	char		*sym;

	if (base < 2 || base > 16)
		return (NULL);
	mod = 0;
	sym = "0123456789abcdef";
	numlen = ft_check(&nb, base, str);
	numlen--;
	while (nb >= (unsigned long long)base)
	{
		mod = nb % (unsigned long long)base;
		nb /= base;
		str[numlen] = sym[mod];
		numlen--;
	}
	str[numlen] = sym[nb];
	return (ft_strdup(str));
}
