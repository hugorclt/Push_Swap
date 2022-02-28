/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:28:56 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/31 11:58:27 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_tab	ft_insert(int ac, char **av)
{
	t_tab	ret;
	int		i;

	i = 1;
	ret.tab = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		ret.tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	ret.size = i - 1;
	ret.pile = 'a';
	return (ret);
}

void	ft_input_init(t_tab *a, char **av, t_tab *b)
{
	if (is_space(av))
	{
		if (verif_input_1(av, b))
		{		
			a->tab = ft_parse_split(av);
			a->size = ft_tab_len(av);
			a->pile = 'a';
		}
		else
		{
			ft_putstr("Error\n");
			exit(127);
		}
	}
	else
	{
		if (!verif_input_1(av, b))
		{
			write(1, "Error\n", 6);
			exit(127);
		}
		return ;
	}
}

void	ft_insert_multi(t_tab *a, int ac, char **av, t_tab *b)
{
	if (verif_input(av, b))
		(*a) = ft_insert(ac, av);
	else
	{
		ft_putstr("Error\n");
		free(b->tab);
		exit(127);
	}
}
