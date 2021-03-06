/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:19:25 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/12 10:19:26 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_update(t_pile *p)
{
	if (!p || p->size == 0)
		return (NULL);
	ft_index(p);
	p->min = pile_min(p->first, p->first);
	p->max = pile_max(p->first, p->first);
	return (p);
}
