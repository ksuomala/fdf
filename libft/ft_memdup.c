/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:49:53 by ksuomala          #+#    #+#             */
/*   Updated: 2020/11/05 19:48:30 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t size)
{
	void	*ptr;

	ptr = ft_memalloc(size);
	if (!ptr || !src)
		return (NULL);
	ft_bzero(ptr, size);
	ft_memcpy(ptr, src, size);
	return (ptr);
}
