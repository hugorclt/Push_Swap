/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:54:34 by hrecolet          #+#    #+#             */
/*   Updated: 2022/02/02 15:02:41 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(char **av)
{
	int	len;
	int	j;
	int	i;

	j = 1;
	i = 1;
	len = 0;
	while (av[len])
		len++;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_doublon(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (i != j)
			{
				if (ft_strcmp(av[i], av[j]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	verif_lg_min(char **av)
{
	int		i;
	long	nb;

	i = 1;
	nb = 0;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 12)
			return (1);
		nb = ft_atol(av[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	verif_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < 48 || av[i][j] > 57) && av[i][j] != '-')
				return (1);
			if (av[i][j] == '-' && (av[i][j + 1] < 48 || av[i][j + 1] > 57))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verif_input(char **av, t_tab *b)
{
	if (verif_int(av) || verif_doublon(av) || verif_lg_min(av))
		return (0);
	if (is_sorted(av))
	{
		free(b->tab);
		exit(0);
	}
	return (1);
}
