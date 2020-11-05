/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:33:30 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/01 21:58:15 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t dest_l;
	size_t i;

	dest_l = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_l] = src[i];
		dest_l++;
		i++;
	}
	dest[dest_l] = '\0';
	return (dest);
}
