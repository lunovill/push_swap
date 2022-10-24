/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:57:02 by lunovill          #+#    #+#             */
/*   Updated: 2022/10/23 18:59:29 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_operation(t_pile *a, t_pile **b, char *op)
{
	if (!ft_strcmp("sa", op))
		return (op_swap(a), 1);
	else if (!ft_strcmp("sb", op))
		return (op_swap(*b), 1);
	else if (!ft_strcmp("ss", op))
		return (op_swap(a), op_swap(*b), 1);
	else if (!ft_strcmp("pa", op))
		return (a = op_push(*b, a), 1);
	else if (!ft_strcmp("pb", op))
		return (*b = op_push(a, *b), 1);
	else if (!ft_strcmp("ra", op))
		return (op_rotate(a), 1);
	else if (!ft_strcmp("rb", op))
		return (op_rotate(*b), 1);
	else if (!ft_strcmp("rr", op))
		return (op_rotate(a), op_rotate(*b), 1);
	else if (!ft_strcmp("rra", op))
		return (op_rrotate(a), 1);
	else if (!ft_strcmp("rrb", op))
		return (op_rrotate(*b), 1);
	else if (!ft_strcmp("rrr", op))
		return (op_rrotate(a), op_rrotate(*b), 1);
	return (0);
}

int	checker(char *args[], t_pile *a, t_pile *b)
{
	int		ret;
	char	*op;

	a = pile_conv(args);
	if (!a)
		return (-1);
	ret = get_next_line(STDIN_FILENO, &op, 1);
	if (ret == -1)
		return (pile_free(a), -1);
	while (ret)
	{
		if (!ft_operation(a, &b, op))
			return (pile_free(a), pile_free(b), ft_free(op),
				get_next_line(STDIN_FILENO, &op, 0), -1);
		ft_free(op);
		ret = get_next_line(STDIN_FILENO, &op, 1);
		if (ret == -1)
			return (pile_free(a), pile_free(b), -1);
	}
	ft_free(op);
	get_next_line(STDIN_FILENO, &op, 0);
	if ((!b || b->size == 0) && pile_is_sort(a))
		return (pile_free(a), pile_free(b), 1);
	return (pile_free(a), pile_free(b), 0);
}

int	main(int argc, char *argv[])
{
	t_pile	*a;
	t_pile	*b;
	int		ret;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (check_all(argv + 1) == -1)
		return (ft_putstr_fd("Error\n", 2), -1);
	ret = checker(argv + 1, a, b);
	if (ret == -1)
		return (-1);
	else if (!ret)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}
