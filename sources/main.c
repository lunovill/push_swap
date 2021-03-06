/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:40:34 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/18 12:12:39 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (check_all(av + 1) == 1)
			return (0);
		av = ft_split(av[1], ' ');
	}
	else
		av++;
	if (check_all(av) == -1)
		ft_putstr_fd("Error\n", 2);
	else
		push_swap(av);
	if (ac == 2)
		ft_ftab(av);
	return (0);
}
