/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:09:09 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/20 22:54:27 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_case	*pile_max(t_case *start, t_case *end)
{
	t_case	*current;
	t_case	*max;

	max = start;
	current = max->next;
	while (current != end)
	{
		if (current->nb > max->nb)
			max = current;
		current = current->next;
	}
	if (current->nb > max->nb)
		max = current;
	return (max);
}
