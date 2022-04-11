/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:20:47 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/12 18:31:18 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_conv(char **args)
{
	t_case			*current;
	t_case			*new;
	t_pile			*pile;
	unsigned int	i;

	current = lst_new();
	pile = lst_init(current);
	if (pile == NULL)
		return (NULL);
	i = 0;
	current->index = 0;
	current->nb = ft_atoi(args[i]);
	while (args[++i])
	{
		new = lst_new();
		new->index = i;
		new->nb = ft_atoi(args[i]);
		lst_add(pile, current, new);
		current = new;
	}
	pile->name = 'a';
	pile->first->befor = current;
	current->next = pile->first;
	pile->size = i;
	pile->min = pile_min(pile->first, pile->first);
	pile->max = pile_max(pile->first, pile->first);
	return (pile);
}
