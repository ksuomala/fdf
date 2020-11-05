/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 10:16:49 by ksuomala          #+#    #+#             */
/*   Updated: 2020/07/14 22:41:37 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	i_new;
	size_t	l;
	char	*ptr;

	i = 0;
	i_new = 0;
	l = ft_strlen(s) - 1;
	while (s[i] == 32 || s[i] == 10 || s[i] == 9)
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[l] == 32 || s[l] == 10 || s[l] == 9)
		l--;
	l = l - i;
	ptr = ft_strnew(l + 1);
	if (!ptr)
		return (NULL);
	while (i_new <= l)
	{
		ptr[i_new] = s[i];
		i_new++;
		i++;
	}
	return (ptr);
}
