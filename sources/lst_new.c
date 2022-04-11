/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:34:24 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:34:52 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_case	*lst_new(void)
{
	t_case	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	return (new);
}
