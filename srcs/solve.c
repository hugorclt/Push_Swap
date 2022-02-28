/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:51:11 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/04 04:08:15 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_moove(t_tab *stack, int index)
{
	int	reverse;

	reverse = stack->size - index;
	if (reverse < index)
	{
		while (reverse > 0)
		{
			reverse_rotate(stack);
			reverse--;
		}
	}
	else
	{
		while (index > 0)
		{
			rotate(stack);
			index--;
		}
	}
}

void	ft_solve_pa(t_tab *stack_a, t_tab *stack_b)
{
	int	i;
	int	min;
	int	j;

	j = 0;
	while (stack_b->size)
	{
		min = stack_b->tab[0];
		i = 0;
		while (i < stack_b->size)
		{
			if (min <= stack_b->tab[i])
			{
				min = stack_b->tab[i];
				j = i;
			}
			i++;
		}
		if (j)
		{
			count_moove(stack_b, j);
		}
		push(stack_b, stack_a);
	}
}

void	ft_reverse_solve(t_tab *a, t_tab *b, int *tab, int i)
{
	int	j;

	j = 0;
	while (j < a->size - 1)
	{
		if (a->tab[0] >= tab[i] && a->tab[0] <= tab[i + 1])
		{
			push(a, b);
			j--;
		}
		else if (a->tab[0] > tab[i + 2])
			break ;
		else
		{
			reverse_rotate(a);
			j++;
		}
	}
	while (j + 1)
	{
		rotate(a);
		j--;
	}
	return ;
}

void	ft_solve(t_tab *stack_a, t_tab *stack_b, int ac)
{
	int	*tab;
	int	i;
	int	j;
	int	med;

	tab = find_percent((*stack_a), ac);
	i = nb_cut(ac - 1);
	med = i / 2;
	i--;
	while (i + 1)
	{
		j = 0;
		while (j < stack_a->size && i > med)
		{
			if (stack_a->tab[0] >= tab[i] && stack_a->tab[0] <= tab[i + 1])
				push(stack_a, stack_b);
			else
				(rotate(stack_a), j++);
		}
		if (med >= i)
			ft_reverse_solve(stack_a, stack_b, tab, i);
		i--;
		ft_solve_pa(stack_a, stack_b);
	}
	free(tab);
}
