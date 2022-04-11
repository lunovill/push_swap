/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:58:01 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/04 12:51:14 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **args)
{
	t_pile	*a;
	t_pile	*b;

	a = pile_conv(args);
	b = NULL;
	if (a == NULL)
		return (-1);
	if (pile_is_sort(a) == 0)
		return (0);
	pile_identifier(a);
	b = pile_b(a, b);
	pile_sort(a, b);
	// lst_print(a);
	// lst_print(b);
	pile_free(a);
	return (0);
}
