/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:20:59 by ksuomala          #+#    #+#             */
/*   Updated: 2020/09/15 20:23:37 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **ptr)
{
	t_list	*temp;

	while (*ptr)
	{
		temp = (*ptr)->next;
		free(*ptr);
		*ptr = temp;
	}
	*ptr = NULL;
}
