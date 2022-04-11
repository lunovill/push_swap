/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:33:38 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:33:58 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_pile	*lst_init(t_case *init)
{
	t_pile	*list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	init->pb = 0;
	init->befor = NULL;
	init->next = NULL;
	list->min = 0;
	list->max = 0;
	list->size = 1;
	list->first = init;
	list->last = init;
	return (list);
}
