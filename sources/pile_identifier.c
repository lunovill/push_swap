/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:00:16 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/18 11:01:23 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pile_identifier(t_pile *p)
{
	unsigned int	id;
	t_case			*min;
	t_case			*current;
	t_case			*next;

	if (!p)
		return ;
	p->min->id = 0;
	p->max->id = p->size - 1;
	id = 0;
	min = p->min;
	while (id++ < p->size - 1)
	{
		current = p->first;
		next = p->max;
		while (current != p->last)
		{
			if (min->nb < current->nb && current->nb < next->nb)
				next = current;
			current = current->next;
		}
		if (min->nb < p->last->nb && p->last->nb < next->nb)
			next = p->last;
		min = next;
		min->id = id;
	}
}
