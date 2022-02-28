/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:40:01 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/10 16:28:00 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_move(int *tab, char pile)
{
	int	temp;

	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
	write(1, "s", 1);
	write(1, &pile, 1);
	write(1, "\n", 1);
}
