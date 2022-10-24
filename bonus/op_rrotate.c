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

#include "checker.h"

int	op_rrotate(t_pile *p)
{
	t_case	*tmp;

	if (!p)
		return (-1);
	if (p->size == 1)
		return (0);
	tmp = p->last->befor;
	p->first = p->last;
	p->last = tmp;
	return (0);
}
