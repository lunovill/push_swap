/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:24:36 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/20 22:54:35 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_case	*pile_min(t_case *start, t_case *end)
{
	t_case	*current;
	t_case	*min;

	min = start;
	current = min->next;
	while (current != end)
	{
		if (current->nb < min->nb)
			min = current;
		current = current->next;
	}
	if (current->nb < min->nb)
		min = current;
	return (min);
}
