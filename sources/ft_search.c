/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:14:22 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/21 01:42:44 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pb(t_case *start, t_case *end, int set)
{
	int		i;
	t_case	*current;

	i = 0;
	current = start->next;
	if (set == 0)
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

static t_case	*ft_next(t_case *start, t_case *end, size_t len)
{
	t_case			*current;
	unsigned int	i;

	if (start == pile_max(start, end))
		return (pile_min(start, end));
	i = 1;
	while (i < len - 1)
	{
		current = start->next;
		while (current != end)
		{
			if (current->id == start->id + i)
				return (current);
			current = current->next;
		}
		i++;
	}
	return (current);
}

static int	ft_calcul(t_pile *p, t_case *start)
{
	t_case			*next;
	t_case			*tmp;
	int pb;

	if (p->size == 2)
		return (1);
	pb = 0;
	tmp = start;
	next = ft_next(tmp, start, p->size);
	while (next != start)
	{
		pb += ft_pb(tmp, next, 0);
		tmp = next;
		next = ft_next(tmp, start, p->size);
	}
	return (pb);
}

int	ft_search(t_pile *p)
{
	t_case			*first;
	t_case			*current;
	// unsigned int	min;
	// unsigned int	tmp;
	int	min;
	int	tmp;
	// int				pb;

	// pb = 0;
	first = p->first;
	current = first->next;
	min = ft_calcul(p, first);
	while (current != p->first)
	{
		tmp = ft_calcul(p, current);
		if (tmp < min)
		{
			first = current;
			min = tmp;
		}
		current = current->next;
	}
	ft_pb(p->first, p->first, 1);
	return (ft_calcul(p, first));
	//ft_printf("solution : %u, %u\n", first->index, min);
	// return (pb);
}
