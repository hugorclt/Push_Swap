/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:17:50 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/04 04:25:35 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_tab_len(char **av)
{
	int		len;
	char	**tab;

	len = 0;
	tab = ft_split(av[1], ' ');
	while (tab[len])
		len++;
	ft_free_char(tab);
	return (len);
}
