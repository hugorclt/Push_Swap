/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:25:25 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/31 11:58:04 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_tab
{
	int		*tab;
	int		size;
	char	pile;
}	t_tab;

t_tab	ft_insert(int ac, char **av);
int		ft_atoi(char *str);
void	swap_move(int *tab, char pile);
void	push(t_tab *stack_from, t_tab *stack_to);
void	ft_swap(int *a, int *b);
void	rotate(t_tab *stack);
void	rotate_all(t_tab *stack_a, t_tab *stack_b);
void	reverse_rotate(t_tab *stack);
void	reverse_rotate_all(t_tab *stack_a, t_tab *stack_b);
int		*find_percent(t_tab stack, int ac);
void	ft_solve(t_tab *stack_a, t_tab *stack_b, int ac);
int		nb_cut(int size);
int		find_size(int *tab);
void	ft_solve_pa(t_tab *stack_a, t_tab *stack_b);
void	count_moove(t_tab *stack, int index);
int		*array_sort(int *tab, int size);
int		verif_input(char **av, t_tab *b);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
long	ft_atol(const char *str);
int		is_space(char **av);
char	**ft_split(char const *s, char c);
int		*ft_parse_split(char **av);
int		verif_input_1(char **av, t_tab *b);
int		ft_tab_len(char **av);
void	ft_input_init(t_tab *a, char **av, t_tab *b);
void	ft_insert_multi(t_tab *a, int ac, char **av, t_tab *b);
void	ft_putstr(char *str);
void	ft_free_char(char **tab);
int		is_sorted(char **av);
int		is_sorted_1(char **av);

#endif
