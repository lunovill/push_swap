/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 09:28:26 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/02 09:28:27 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rotate(t_pile *p, int set)
{
	t_case	*tmp;

	if (!p)
		return (-1);
	if (p->size == 1)
		return (0);
	tmp = p->first;
	p->first = p->first->next;
	p->last = tmp;
	if (set)
		ft_printf("r%c\n", p->name);
	return (0);
}
