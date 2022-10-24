/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 06:48:13 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/06 06:48:14 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_index(t_pile *p)
{
	t_case			*current;
	unsigned int	i;

	if (!p)
		return ;
	current = p->first;
	i = 0;
	while (i < p->size)
	{
		current->index = i++;
		current = current->next;
	}
}
