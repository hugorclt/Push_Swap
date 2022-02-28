/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:26:51 by hrecolet          #+#    #+#             */
/*   Updated: 2022/02/02 15:04:53 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_solve_3(t_tab *stack)
{
	if (stack->size == 2)
		swap_move(stack->tab, stack->pile);
	else if (stack->tab[0] > stack->tab[1])
	{
		if (stack->tab[0] > stack->tab[2] && stack->tab[1] < stack->tab[2])
			rotate(stack);
		else if (stack->tab[0] > stack->tab[2] && stack->tab[1] > stack->tab[2])
		{
			swap_move(stack->tab, stack->pile);
			reverse_rotate(stack);
		}
		else if (stack->tab[0] < stack->tab[2] && stack->tab[1] < stack->tab[2])
			swap_move(stack->tab, stack->pile);
	}
	else if (stack->tab[0] < stack->tab[1])
	{
		if (stack->tab[0] > stack->tab[2] && stack->tab[1] > stack->tab[2])
			reverse_rotate(stack);
		else if (stack->tab[0] < stack->tab[2] && stack->tab[1] > stack->tab[2])
		{
			swap_move(stack->tab, stack->pile);
			rotate(stack);
		}
	}
}

int	find_median(int *av, int ac)
{
	int	median;
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * ac);
	if (!tab)
		return (0);
	while (i < ac)
	{
		tab[i] = av[i];
		i++;
	}
	tab = array_sort(tab, ac);
	if (ac % 2 == 0)
		median = tab[(ac / 2) - 1];
	else
		median = tab[(ac / 2)];
	free(tab);
	return (median);
}

void	ft_solve_5(t_tab *a, t_tab *b)
{
	int	median;
	int	i;

	i = 0;
	median = find_median(a->tab, a->size);
	while (i < a->size)
	{
		if (a->tab[0] < median)
			push(a, b);
		else
		{
			rotate(a);
			i++;
		}
	}
	ft_solve_3(a);
	if (b->size > 1)
	{
		if (b->tab[0] < b->tab[1])
			swap_move(b->tab, b->pile);
	}
	while (b->size)
		push(b, a);
}

void	ft_solve_all(t_tab *a, t_tab *b)
{
	if (a->size == 2 || a->size == 3)
		ft_solve_3(a);
	else if (a->size == 4 || a->size == 5)
		ft_solve_5(a, b);
	else if (a->size > 5)
		ft_solve(a, b, a->size + 1);
}

int	main(int ac, char **av)
{
	t_tab	a;
	t_tab	b;

	b.tab = malloc(sizeof(int) * (ac - 1));
	if (!b.tab)
		return (0);
	b.size = 0;
	b.pile = 'b';
	if (ac - 1 <= 0)
	{
		free(b.tab);
		return (0);
	}
	else
	{
		ft_insert_multi(&a, ac, av, &b);
		ft_solve_all(&a, &b);
		free(a.tab);
		free(b.tab);
	}
}
