/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 01:12:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/04 12:50:44 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// static t_pile	*ft_is_rotate(t_pile *a, t_pile *b, t_case *start, t_case *end)
// {
// 	while (a->first != start)
// 		op_rotate(a, 1);
// 	while (a->first != end)
// 	{
// 		if (a->first->pb == 1)
// 			b = op_push(a, b);
// 		else
// 			op_rotate(a, 1);
// 	}
// 	op_push(a, b);
// 	return (b);
// }

// static t_pile	*ft_is_rrotate(t_pile *a, t_pile *b, t_case *start, t_case *end)
// {
// 	while (a->first != start)
// 		op_rrotate(a, 1);
// 	while (a->first != end)
// 	{
// 		if (a->first->pb == 1)
// 			b = op_push(a, b);
// 		else
// 			op_rrotate(a, 1);
// 	}
// 	op_push(a, b);
// 	return (b);
// }

static void	ft_pb(t_pile *a, t_case **first, t_case **last)
{
	*first = a->first;
	*last = a->last;
	while ((*first)->pb != 1)
		*first = (*first)->next;
	while ((*last)->pb != 1)
		*last = (*last)->befor;
}

static t_pile *pb(t_pile *a, t_pile *b, t_case *last)
{
	unsigned int med;

	med = a->size / 2;
	while (a->first != last)
	{
		while (!a->first->pb)
			op_rotate(a, 1);
		b = op_push(a, b);
		if (b->first->id < med)
				op_rotate(b, 1);
		if (b && b->first == last)
			break;
	}
	return (b);
}

t_pile	*pile_b(t_pile *a, t_pile *b)
{
	t_case	*first;
	t_case	*last;

	if (ft_search(a) == 0)
		return (NULL);
	// ft_printf("%i et %i\n", first->nb, last->nb);
	// ft_printf("%u et %u\n", first->index, a->size - last->index);
	ft_pb(a, &first, &last);
	b = pb(a, b, last);
	// if (first->index <= a->size - last->index)
	// 	b = ft_is_rotate(a, b, first, last);
	// else
	// 	b = ft_is_rrotate(a, b, last, first);
	a = pile_update(a);
	b = pile_update(b);
	ft_index(a);
	ft_index(b);
	return (b);
}
