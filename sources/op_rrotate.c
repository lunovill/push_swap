/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 09:26:44 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/02 09:26:46 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rrotate(t_pile *p, int set)
{
	t_case	*tmp;

	if (!p)
		return (-1);
	if (p->size == 1)
		return (0);
	tmp = p->last->befor;
	p->first = p->last;
	p->last = tmp;
	if (set)
		ft_printf("rr%c\n", p->name);
	return (0);
}
