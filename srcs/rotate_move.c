/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:51:06 by hrecolet          #+#    #+#             */
/*   Updated: 2021/12/31 13:08:36 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_tab *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->tab[0];
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = temp;
	write(1, "r", 1);
	write(1, &stack->pile, 1);
	write(1, "\n", 1);
}

void	rotate_all(t_tab *stack_a, t_tab *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_tab *stack)
{
	int	i;
	int	temp;

	i = 1;
	while (i < stack->size)
	{
		temp = stack->tab[stack->size - i];
		stack->tab[stack->size - i] = stack->tab[stack->size - i - 1];
		stack->tab[stack->size - i - 1] = temp;
		i++;
	}
	write(1, "rr", 2);
	write(1, &stack->pile, 1);
	write(1, "\n", 1);
}

void	reverse_rotate_all(t_tab *stack_a, t_tab *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
