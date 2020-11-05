/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:02:20 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/14 20:16:19 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*str;
	unsigned char		*ret;

	if (dest || src)
	{
		i = 0;
		str = src;
		ret = dest;
		while (i < n)
		{
			ret[i] = str[i];
			i++;
		}
	}
	return (dest);
}
