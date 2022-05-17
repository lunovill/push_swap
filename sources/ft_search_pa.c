/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:45:37 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/14 16:49:31 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	ft_calcul_pa2(t_case *case_a, t_pile *b, t_case *case_b)
{
	unsigned int	count;

	if (case_a->index < case_b->index
		&& case_b->index - case_a->index > b->size - case_b->index)
		count = case_a->index + (b->size - case_b->index);
	else
	{
		if (case_a->index > case_b->index)
			count = case_a->index;
		else
			count = case_b->index;
	}
	return (count);
}

static unsigned int	ft_calcul_pa(t_pile *a, t_pile *b, t_case *case_b)
{
	t_case			*case_a;
	unsigned int	count;

	case_a = ft_next_pa(a, case_b);
	if (case_a->index <= a->size / 2)
		count = ft_calcul_pa2(case_a, b, case_b);
	else
	{
		if (case_a->index > case_b->index
			&& case_a->index - case_b->index > case_b->index)
			count = case_b->index + (a->size - case_a->index);
		else
		{
			if (a->size - case_a->index > b->size - case_b->index)
				count = a->size - case_a->index;
			else
				count = b->size - case_b->index;
		}
	}
	return (count);
}

t_case	*ft_search_pa(t_pile *a, t_pile *b)
{
	t_case			*case_b;
	t_case			*current;
	unsigned int	min;
	unsigned int	tmp;

	case_b = b->first;
	current = case_b->next;
	min = ft_calcul_pa(a, b, case_b);
	while (current != b->first)
	{
		tmp = ft_calcul_pa(a, b, current);
		if (tmp < min)
		{
			case_b = current;
			min = tmp;
		}
		current = current->next;
	}
	return (case_b);
}
