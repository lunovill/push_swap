/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:12:31 by lunovill          #+#    #+#             */
/*   Updated: 2022/05/17 21:05:42 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(char **args)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][0] == '-' && args[i][1] != '\0')
			j++;
		while (args[i][j])
			if (ft_strichr("0123456789", args[i][j++]) == -1)
				return (-1);
		i++;
	}
	return (1);
}

static int	check_duplicates(char **args)
{
	unsigned int	i;
	unsigned int	j;

	if (!args[1])
		return (1);
	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
			if (ft_strcmp(args[i], args[j++]) == 0)
				return (-1);
		i++;
	}
	return (1);
}

static int	check_overflow(char **args)
{
	unsigned int	i;
	size_t			len;

	i = -1;
	while (args[++i])
	{
		len = ft_strlen(args[i]);
		if (args[i][0] == '-')
		{
			if (len > 11)
				return (-1);
			if ((len == 11 && args[i][1] > '2') || (len == 11 &&
				(args[i][1] == '2' && ft_atoi(args[i] + 2) > 147483648)))
				return (-1);
		}
		else
		{
			if (len > 10)
				return (-1);
			if ((len == 10 && args[i][0] > '2') || (len == 10 &&
				(args[i][0] == '2' && ft_atoi(args[i] + 1) > 147483647)))
				return (-1);
		}
	}
	return (1);
}

int	check_all(char **args)
{
	if (check_args(args) == 1
		&& check_duplicates(args) == 1
		&& check_overflow(args) == 1)
		return (1);
	return (-1);
}
