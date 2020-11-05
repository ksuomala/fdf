/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:30:51 by ksuomala          #+#    #+#             */
/*   Updated: 2020/09/07 19:22:37 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*str2;
	unsigned char		*dst2;

	if (!(dest || src))
		return (dest);
	str2 = src;
	dst2 = dest;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			dst2[n] = str2[n];
	}
	return (dest);
}
