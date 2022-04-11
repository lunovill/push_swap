/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:11:34 by lunovill          #+#    #+#             */
/*   Updated: 2022/03/18 14:30:12 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "list.h"

int		check_all(char **args);
int		ft_search(t_pile *p);
// int	ft_pile(t_pile *p);
t_case	*ft_rrsearch(t_pile *p);
t_case	*pile_min(t_case *start, t_case *end);
t_case	*pile_max(t_case *start, t_case *end);
t_pile	*pile_conv(char **args);
void	pile_identifier(t_pile *p);
void	ft_index(t_pile *p);
void    pile_sort(t_pile *a, t_pile *b);
int		pile_is_sort(t_pile *p);
void	pile_free(t_pile *p);
t_pile	*pile_b(t_pile *a, t_pile *b);
t_pile	*op_push(t_pile *p1, t_pile *p2);
t_pile  *pile_update(t_pile *p);
int		op_rotate(t_pile *p, int set);
int		op_rrotate(t_pile *p, int set);
int	op_rotate_all(t_pile *p1, t_pile *p2);
int	op_rrotate_all(t_pile *p1, t_pile *p2);
int		op_swap(t_pile *p);
int		push_swap(char **args);

//void	pile_print(t_pile a, t_pile b);

#endif
