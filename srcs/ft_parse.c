/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:43:37 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/31 13:08:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	verif_doublon_1(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
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

int	verif_lg_min_1(char **av)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	verif_int_1(char **av)
{
	int	i;
	int	j;

	i = 0;
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

int	*ft_parse_split(char **av)
{
	char	**tab;
	int		i;
	int		*ret;
	int		len;

	tab = ft_split(av[1], ' ');
	len = 0;
	while (tab[len])
		len++;
	i = 0;
	ret = malloc(sizeof(int) * len);
	if (!ret)
		return (0);
	while (tab[i])
	{
		ret[i] = ft_atoi(tab[i]);
		i++;
	}
	ft_free_char(tab);
	return (ret);
}

int	verif_input_1(char **av, t_tab *b)
{
	char	**tab;

	tab = ft_split(av[1], ' ');
	if (verif_int_1(tab) || verif_doublon_1(tab) || verif_lg_min_1(tab))
	{
		ft_free_char(tab);
		free(b->tab);
		return (0);
	}
	if (is_sorted_1(tab))
	{
		ft_free_char(tab);
		free(b->tab);
		exit(0);
	}
	ft_free_char(tab);
	return (1);
}
