/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:35:03 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/09 18:31:16 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_space(char **av)
{
	int	i;

	i = 1;
	if (!av[1][0])
		exit(127);
	while (av[1][i])
	{
		if (av[1][i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted_1(char **av)
{
	int	len;
	int	j;
	int	i;

	j = 0;
	i = 0;
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
