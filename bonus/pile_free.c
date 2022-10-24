/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:23:12 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/06 06:50:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "checker.h"

void	pile_free(t_pile *p)
{
	if (p)
	{
		if (p->size)
		{
			p->last->next = NULL;
			while (p->first)
				lst_rmv(p, p->first);
		}
		free(p);
	}
	p = NULL;
}
