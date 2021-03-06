/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 01:12:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/13 03:02:23 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*ft_is_rotate(t_pile *a, t_pile *b, t_case *start, t_case *end)
{
	unsigned int	med;

	med = a->size / 2;
	while (a->first != start)
		op_rotate(a, 1);
	while (start != end && a->first != end)
	{
		if (a->first->pb == 1)
		{
			b = op_push(a, b);
			if (b->first->id < med)
			{
				if (a->first->pb == 1)
					op_rotate(b, 1);
				else
					op_rotate_all(a, b);
			}
		}
		else
			op_rotate(a, 1);
	}
	b = op_push(a, b);
	if (b->first->id < med)
		op_rotate(b, 1);
	return (b);
}

static t_pile	*ft_is_rrotate(t_pile *a, t_pile *b, t_case *start, t_case *end)
{
	unsigned int	med;

	med = a->size / 2;
	while (a->first != start)
		op_rrotate(a, 1);
	if (start != end)
	{
		while (a->first != end)
		{
			if (a->first->pb == 1)
			{
				b = op_push(a, b);
				if (b->first->id < med)
					op_rotate(b, 1);
			}
			else
				op_rrotate(a, 1);
		}
	}
	b = op_push(a, b);
	if (b->first->id < med)
		op_rotate(b, 1);
	return (b);
}

static void	ft_pb(t_pile *a, t_case **first, t_case **last)
{
	*first = a->first;
	*last = a->last;
	while ((*first)->pb != 1)
		*first = (*first)->next;
	while ((*last)->pb != 1)
		*last = (*last)->befor;
}

t_pile	*pile_b(t_pile *a, t_pile *b)
{
	t_case	*first;
	t_case	*last;

	if (ft_search(a) == 0)
		return (NULL);
	ft_pb(a, &first, &last);
	if (first->index <= a->size - last->index)
		b = ft_is_rotate(a, b, first, last);
	else
		b = ft_is_rrotate(a, b, last, first);
	a = pile_update(a);
	b = pile_update(b);
	ft_index(a);
	ft_index(b);
	return (b);
}
