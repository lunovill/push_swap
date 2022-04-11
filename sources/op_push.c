/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 06:12:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/02 09:17:53 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*op_push(t_pile *p1, t_pile *p2)
{
	t_case	*add;

	if (!p1)
		return (NULL);
	add = p1->first;
	// if (p1->size > 1)
	// {
	p1->first = p1->first->next;
	p1->first->befor = p1->last;
	p1->last->next = p1->first;
	// }
	// else
	// {
	// 	p1->min = NULL;
	// 	p1->max = NULL;
	// 	p1->first = NULL;
	// 	p1->last = NULL;
	// }
	if (!p2)
	{
		p2 = lst_init(add);
		if (p1->name == 'a')
			p2->name = 'b';
		else
			p2->name = 'a';
		add->befor = add;
		add->next = add;
		p2->first = add;
		p2->last = add;
	}
	else
	{
		add->befor = p2->last;
		add->next = p2->first;
		p2->first->befor = add;
		p2->last->next = add;
		p2->first = add;
		p2->size++;
	}
	p1->size--;
	ft_printf("p%c\n", p2->name);
	return (p2);
}
