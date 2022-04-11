/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:25:23 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:31:32 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "libft.h"

typedef struct s_case	t_case;
struct			s_case
{
	unsigned int	index;
	int				nb;
	unsigned int	id;
	int				pb;
	t_case			*befor;
	t_case			*next;
};

typedef struct s_pile
{
	char	name;
	t_case	*min;
	t_case	*max;
	t_case	*first;
	t_case	*last;
	size_t	size;
}				t_pile;

t_case			*lst_new(void);
t_pile			*lst_init(t_case *init);
int				lst_add(t_pile *list, t_case *befor, t_case *add);
int				lst_rmv(t_pile *list, t_case *remove);
int				lst_print(t_pile *list);

#endif