/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:40:33 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/13 18:44:30 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long long *nb, long base)
{
	int			i;
	long long	n;

	i = 1;
	if (*nb < 0)
		i++;
	n = *nb;
	while (n >= base || n <= (base * -1))
	{
		n /= base;
		i++;
	}
	return (i);
}

static int	ft_check(long long *nb, long base, char str[20], char *sym)
{
	int		mod;
	int		numlen;

	numlen = ft_numlen(nb, base);
	str[numlen] = '\0';
	if (*nb < 0)
	{
		str[0] = '-';
		*nb *= -1;
	}
	if (*nb < -9223372036854775807)
	{
		mod = *nb % base;
		mod *= -1;
		*nb /= base;
		*nb *= -1;
		str[numlen - 1] = sym[mod];
		numlen--;
	}
	return (numlen);
}

char		*ft_itoa_base(long long nb, long base)
{
	int			numlen;
	long long	mod;
	char		str[20];
	char		*sym;

	if (base < 2 || base > 16)
		return (NULL);
	mod = 0;
	sym = "0123456789abcdef";
	numlen = ft_check(&nb, base, str, sym);
	numlen--;
	while (nb >= base)
	{
		mod = nb % base;
		nb /= base;
		str[numlen] = sym[mod];
		numlen--;
	}
	str[numlen] = sym[nb];
	return (ft_strdup(str));
}
