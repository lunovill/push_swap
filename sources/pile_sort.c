/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 06:49:03 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/07 07:10:57 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void pile_rotate(t_pile *a, t_case *case_a, t_pile *b, t_case *case_b)
{
	while (a->first != case_a || b->first != case_b)
	{
		if (a->first != case_a && b->first == case_b)
			op_rotate(a, 1);
		else if (a->first == case_a && b->first != case_b)
			op_rotate(b, 1);
		else
			op_rotate_all(a, b);
	}
}

static void pile_rrotate(t_pile *a, t_case *case_a, t_pile *b, t_case *case_b)
{
	while (a->first != case_a || b->first != case_b)
	{
		if (a->first != case_a && b->first == case_b)
			op_rrotate(a, 1);
		else if (a->first == case_a && b->first != case_b)
			op_rrotate(b, 1);
		else
			op_rrotate_all(a, b);
	}
}

static void pile_push(t_pile *a, t_case *case_a, t_pile *b, t_case *case_b)
{
	if (case_a->index <= a->size / 2)
	{
		if (case_a->index < case_b->index && case_b->index - case_a->index > b->size - case_b->index)
			while (a->first != case_a || b->first != case_b)
			{
				if (a->first != case_a)
					op_rotate(a, 1);
				if (b->first != case_b)
					op_rrotate(b, 1);
			}
		else
			pile_rotate(a, case_a, b, case_b);
	}
	else
	{
		if (case_a->index > case_b->index && case_a->index - case_b->index > case_b->index)
			while (a->first != case_a || b->first != case_b)
			{
				if (a->first != case_a)
					op_rrotate(a, 1);
				if (b->first != case_b)
					op_rotate(b, 1);
			}
		else
			pile_rrotate(a, case_a, b, case_b);
	}
	op_push(b, a);
	a = pile_update(a);
	b = pile_update(b);
}

void    pile_sort(t_pile *a, t_pile *b)
{
	t_case	*current;

	current = a->first;
	if (b && b->max->nb > a->max->nb)
			pile_push(a, a->min, b, b->max);
	while (b)
	{
		while (current->id - 1 != b->max->id)
			current = current->next;
		pile_push(a, current, b, b->max);
		if (b->size == 0)
		{
			free(b);
			b = NULL;
		}
	}
	while (a->first != a->min)
	{
		if (a->min->index <= a->size / 2)
			op_rotate(a, 1);
		else
			op_rrotate(a, 1);
	}
}
