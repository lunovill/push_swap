/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 06:49:03 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/14 16:52:16 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pile_rotate(t_pile *a, t_case *case_a, t_pile *b, t_case *case_b)
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

static void	pile_rrotate(t_pile *a, t_case *case_a, t_pile *b, t_case *case_b)
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

static void	pile_sort2(t_pile *a, t_case *case_a, t_pile *b, t_case *case_b)
{
	if (case_a->index < case_b->index
		&& case_b->index - case_a->index > b->size - case_b->index)
	{
		while (a->first != case_a || b->first != case_b)
		{
			if (a->first != case_a)
				op_rotate(a, 1);
			if (b->first != case_b)
				op_rrotate(b, 1);
		}
	}
	else
		pile_rotate(a, case_a, b, case_b);
}

static void	pile_push(t_pile *a, t_case *case_a, t_pile *b, t_case *case_b)
{
	if (case_a->index <= a->size / 2)
		pile_sort2(a, case_a, b, case_b);
	else
	{
		if (case_a->index > case_b->index
			&& case_a->index - case_b->index > case_b->index)
		{
			while (a->first != case_a || b->first != case_b)
			{
				if (a->first != case_a)
					op_rrotate(a, 1);
				if (b->first != case_b)
					op_rotate(b, 1);
			}
		}
		else
			pile_rrotate(a, case_a, b, case_b);
	}
	op_push(b, a);
	a = pile_update(a);
	b = pile_update(b);
}

void	pile_sort(t_pile *a, t_pile *b)
{
	t_case	*case_a;
	t_case	*case_b;

	while (b)
	{
		case_b = ft_search_pa(a, b);
		case_a = ft_next_pa(a, case_b);
		pile_push(a, case_a, b, case_b);
		if (b->size == 0)
		{
			free(b);
			b = NULL;
		}
	}
	if (a->size == 3)
		ft_three(a);
	while (a->first != a->min)
	{
		if (a->min->index <= a->size / 2)
			op_rotate(a, 1);
		else
			op_rrotate(a, 1);
	}
}
