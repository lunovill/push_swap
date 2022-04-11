/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 05:55:17 by lunovill          #+#    #+#             */
/*   Updated: 2022/04/07 05:55:18 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rrotate_all(t_pile *p1, t_pile *p2)
{
	if (!p1 || !p2)
		return (-1);
	op_rrotate(p1, 0);
	op_rrotate(p2, 0);
	ft_putstr("rrr\n");
	return (0);
}
