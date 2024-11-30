/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:07:51 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/30 10:45:50 by cwolf            ###   ########.fr       */
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

//void		print_list(t_ps_list *head);

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
void		rr(t_ps_list **a, t_ps_list **b);
void		rra(t_ps_list **a);
void		rrb(t_ps_list **b);
void		rrr(t_ps_list **a, t_ps_list **b);
int			in_order(t_ps_list **list);
int			two_nodes(t_ps_list **list);
int			three_nodes(t_ps_list **list);
int			count_list_len(t_ps_list **list);
void		sort_three(t_ps_list **list);
void		update_notes_a(t_ps_list **a, t_ps_list **b);
t_ps_list	*find_max(t_ps_list **list);
t_ps_list	*find_min(t_ps_list **list);
void		turk_algorithm(t_ps_list **a, t_ps_list **b);
t_ps_list	*find_cheapest(t_ps_list **list);
void		update_index_median(t_ps_list **list);
void		rotate_both(t_ps_list **a, t_ps_list **b, t_ps_list *cheapest_node);
void		reverse_rotate_both(t_ps_list **a, t_ps_list **b,
				t_ps_list *cheapest_node);
void		check_top_of_list_a_1(t_ps_list **a, t_ps_list *cheapest_node);
void		check_top_of_list_b_1(t_ps_list **b, t_ps_list *cheapest_node);
void		check_top_of_list_a_2(t_ps_list **a, t_ps_list *top_node);
void		check_top_of_list_b_2(t_ps_list **a, t_ps_list *top_node);
void		update_nodes_b(t_ps_list **a, t_ps_list **b);
void		start_with_min(t_ps_list **list);
void		update_cheapest(t_ps_list	**list);
void		rotate_both_b(t_ps_list **a, t_ps_list **b,
				t_ps_list *cheapest_node);
void		reverse_rotate_both_b(t_ps_list **a, t_ps_list **b,
				t_ps_list *cheapest_node);

#endif
