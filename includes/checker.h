/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:57:26 by lunovill          #+#    #+#             */
/*   Updated: 2022/10/23 18:57:28 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "list.h"

void	ft_index(t_pile *p);
void	pile_free(t_pile *p);

int		check_all(char **args);
int		op_rotate(t_pile *p);
int		op_rrotate(t_pile *p);
int		op_swap(t_pile *p);
int		pile_is_sort(t_pile *p);

t_case	*pile_min(t_case *start, t_case *end);
t_case	*pile_max(t_case *start, t_case *end);

t_pile	*op_push(t_pile *p1, t_pile *p2);
t_pile	*pile_conv(char **args);

#endif
