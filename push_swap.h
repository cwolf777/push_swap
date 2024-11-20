/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:07:51 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/20 13:41:07 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct structure
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct structure	*target_node;
	struct structure	*next;
	struct structure	*prev;
}	t_ps_list;

void		print_list(t_ps_list *head);

int			check_syntax(char *str);
int			check_duplicate(t_ps_list *a, int n);
void		free_list(t_ps_list **a);
long		ft_atolo(const char *str);
void		init_list_a(t_ps_list **a, char **args);
int			check_syntax(char *str);
int			check_duplicate(t_ps_list *a, int n);
void		free_list(t_ps_list **a);
void		sa(t_ps_list **a);
void		sb(t_ps_list **b);
void		ss(t_ps_list **a, t_ps_list **b);
void		pa(t_ps_list **a, t_ps_list **b);
void		pb(t_ps_list **b, t_ps_list **a);
void		ra(t_ps_list **a);
void		rb(t_ps_list **b);
void		rra(t_ps_list **a);
void		rrb(t_ps_list **b);
void		rrr(t_ps_list **a, t_ps_list **b);

# endif
