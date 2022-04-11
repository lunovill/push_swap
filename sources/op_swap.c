/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 09:12:14 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/02 09:12:16 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_swap(t_pile *p)
{
	t_case	*swap1;
	t_case	*swap2;
	t_case	*tmp;

	if (!p || p->size < 2)
		return (-1);
	swap1 = p->first;
	swap2 = p->first->next;
	swap1->index = 1;
	swap2->index = 0;
	tmp = p->first->next->next;
	p->last->next = swap2;
	swap1->befor = swap2;
	swap1->next = tmp;
	swap2->befor = p->last;
	swap2->next = swap1;
	tmp->befor = swap1;
	p->first = swap2;
	ft_printf("s%c\n", p->name);
	return (0);
}
