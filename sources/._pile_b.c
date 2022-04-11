/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 01:12:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/07 13:11:38 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static t_pile	*ft_is_rotate(t_pile *a, t_pile *b, t_case *push, int set)
{
	while (a->first != push)
		op_rotate(a, 1);
	b = op_push(a, b);
	if (b && set)
		op_rotate(b, 1);
	return (b);
}

static t_pile	*ft_is_rrotate(t_pile *a, t_pile *b, t_case *push, int set)
{
	while (a->first != push)
		op_rrotate(a, 1);
	b = op_push(a, b);
	if (b && set)
		op_rotate(b, 1);
	return (b);
}

static int	ft_pb(t_pile *a, t_case **min, t_case **max)
{
	t_case	*current;

	*min = a->first;
	while ((*min)->pb != 1 && *min != a->last)
		*min = (*min)->next;
	if ((*min)->pb == 0)
		return (0);
	*max = *min;
	current = (*min)->next;
	while (current != a->first)
	{
		if (current->pb == 1 && current->nb < (*min)->nb)
			*min = current;
		if (current->pb == 1 && current->nb > (*max)->nb)
			*max = current;
		current = current->next;
	}
	return (1);
}

t_pile	*pile_b(t_pile *a, t_pile *b)
{
	int i;
	t_case	*min;
	t_case	*max;

	i = ft_search(a);
	if (i == 0)
		return (NULL);
	// ft_printf("%i et %i\n", first->nb, last->nb);
	// ft_printf("%u et %u\n", first->index, a->size - last->index);
	while (ft_pb(a, &min, &max))
	{
		if (min->index < max->index)
		{
			if (min->index <= a->size - max->index)
				b = ft_is_rotate(a, b, min, 0);
			else
				b = ft_is_rrotate(a, b, max, 1);
		}
		else
		{
			if (max->index <= a->size - min->index)
				b = ft_is_rotate(a, b, max, 1);
			else
				b = ft_is_rrotate(a, b, min, 0);
		}
	}
	a = pile_update(a);
	b = pile_update(b);
	ft_index(a);
	ft_index(b);
	return (b);
}
