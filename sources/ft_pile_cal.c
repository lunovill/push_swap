/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_cal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:58:14 by lunovill          #+#    #+#             */
/*   Updated: 2022/10/23 18:58:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pb(t_case *start, t_case *end, int set)
{
	int		i;
	t_case	*current;

	i = 0;
	current = start->next;
	if (set)
	{
		while (current != end)
		{
			current->pb = 1;
			current = current->next;
			i++;
		}
	}
	else
	{
		start->next->pb = 0;
		while (current != end)
		{
			current->pb = 0;
			current = current->next;
		}
		current->pb = 0;
	}
	return (i);
}

static t_case	*ft_next(t_case *start, t_case *end)
{
	t_case			*current;

	current = start->next;
	if (current != pile_max(start, end))
		while (current->nb < start->nb && current != end)
			current = current->next;
	else
		return (start->next);
	return (current);
}

static int	ft_calcul(t_pile *p, t_case *start)
{
	t_case			*next;
	t_case			*tmp;
	int				pb;

	if (p->size == 2)
		return (1);
	tmp = start;
	next = ft_next(tmp, start);
	pb = ft_pb(tmp, next, 1);
	while (next != start)
	{
		tmp = ft_next(next, start);
		pb += ft_pb(next, tmp, 1);
		next = tmp;
	}
	return (pb);
}

int	ft_pile(t_pile *p)
{
	t_case	*first;
	t_case	*current;
	int		pb;
	int		tmp;

	if (!p)
		return (-1);
	first = p->first;
	current = p->first->next;
	pb = ft_calcul(p, first);
	while (current != p->first)
	{
		tmp = ft_calcul(p, current);
		if (tmp < pb)
		{
			first = current;
			pb = tmp;
		}
		current = current->next;
	}
	ft_pb(p->first, p->first, 0);
	return (ft_calcul(p, first));
}
