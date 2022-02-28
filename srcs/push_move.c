/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:00:07 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/31 11:59:50 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_tab *from, t_tab *to)
{
	int	i;

	i = 1;
	if (from->size <= 0)
		return ;
	else
	{
		to->size++;
		while (i < to->size)
		{
			ft_swap(&to->tab[to->size - i], &to->tab[to->size - i - 1]);
			i++;
		}
		to->tab[0] = from->tab[0];
		i = 0;
		while (i < from->size - 1)
		{
			from->tab[i] = from->tab[i + 1];
			i++;
		}
		from->size--;
		write(1, "p", 1);
		write(1, &to->pile, 1);
		write(1, "\n", 1);
	}
}
