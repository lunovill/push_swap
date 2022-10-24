/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 06:12:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/12 05:02:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_pile	*ft_new_pile(t_pile *p1, t_case *init)
{
	t_pile	*p2;

	p2 = lst_init(init);
	if (p1->name == 'a')
		p2->name = 'b';
	else
		p2->name = 'a';
	init->befor = init;
	init->next = init;
	p2->first = init;
	p2->last = init;
	return (p2);
}

t_pile	*op_push(t_pile *p1, t_pile *p2)
{
	t_case	*add;

	if (!p1)
		return (NULL);
	add = p1->first;
	p1->first = p1->first->next;
	p1->first->befor = p1->last;
	p1->last->next = p1->first;
	if (!p2)
		p2 = ft_new_pile(p1, add);
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
	return (p2);
}
