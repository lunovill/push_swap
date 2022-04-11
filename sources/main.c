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

/*void	pile_print(t_pile a, t_pile b)
  {
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = 0;
  if (a.size < b.size && i == 0)
  while (j < (b.size - a.size))
  {
  ft_putstr("\t\t");
  if (b.tab[j] >= 0)
  ft_putchar(' ');
  ft_putnbr(b.tab[j++]);
  ft_putstr("\n");
  }
  if (a.size > b.size && j == 0)
  while (i < (a.size - b.size))
  {
  if (a.tab[i] >= 0)
  ft_putchar(' ');
  ft_putnbr(a.tab[i++]);
  ft_putstr("\t\t\t\n");
  }
  while (i < a.size && j < b.size)
  {
  if (a.tab[i] >= 0)
  ft_putchar(' ');
  ft_putnbr(a.tab[i++]);
  ft_putstr("\t\t");
  if (b.tab[j] >= 0)
  ft_putchar(' ');
  ft_putnbr(b.tab[j++]);
  ft_putstr("\n");
  }
  ft_putstr("---------\t---------\n");
  ft_putstr("    a    \t    b    \n");
  return;
  }
  */

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
