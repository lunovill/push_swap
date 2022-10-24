/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:35:13 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 04:37:19 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	lst_print(t_pile *list)
{
	unsigned int	i;
	t_case			*current;

	if (!list)
		return (-1);
	current = list->first;
	i = list->size;
	ft_printf("\n### PILE %c ###\n", list->name);
	while ((current != NULL) && i--)
	{
		ft_printf("case n°%u\n", list->size - i);
		ft_printf("index    : %u\n", current->index);
		ft_printf("nombre   : %i\n", current->nb);
		ft_printf("position : %u\n", current->id);
		ft_putchar('\n');
		current = current->next;
	}
	ft_putstr("(null)\n");
	ft_printf("\ncase : %u\n", list->size);
	return (0);
}
