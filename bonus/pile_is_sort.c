/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:09:14 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/18 11:16:10 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	pile_is_sort(t_pile *p)
{
	t_case	*current;
	t_case	*next;

	current = p->first;
	while (current != p->last)
	{
		next = current->next;
		if (current->nb > next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}
