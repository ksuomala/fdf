/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 09:44:05 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/02 03:04:52 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i] || i == n)
		return (1);
	return (0);
}
