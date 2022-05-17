/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:43:49 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/13 03:43:51 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_case	*ft_next_pa(t_pile *a, t_case *case_b)
{
	t_case			*current;
	unsigned int	i;
	unsigned int	len;

	if (case_b->nb > a->max->nb)
		return (a->min);
	i = 1;
	len = a->max->id;
	while (i < len)
	{
		current = a->first;
		while (current != a->last)
		{
			if (current->id == case_b->id + i)
				return (current);
			current = current->next;
		}
		if (current->id == case_b->id + i)
			return (current);
		i++;
	}
	return (current);
}
