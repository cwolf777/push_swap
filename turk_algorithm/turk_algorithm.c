/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:20:16 by cwolf             #+#    #+#             */
/*   Updated: 2024/12/10 08:43:59 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_a_to_b(t_ps_list **a, t_ps_list **b);
static void	move_b_to_a(t_ps_list **a, t_ps_list **b);

void	turk_algorithm(t_ps_list **a, t_ps_list **b)
{
	if (count_list_len(a) > 3 && in_order(a) == 0)
		pb(b, a);
	if (count_list_len(a) > 3 && in_order(a) == 0)
		pb(b, a);
	while (count_list_len(a) > 3 && in_order(a) == 0)
	{
		update_notes_a(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		update_nodes_b(a, b);
		move_b_to_a(a, b);
	}
	update_index_median(a);
	start_with_min(a);
}

static void	move_a_to_b(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*cheapest_node;

	cheapest_node = find_cheapest(a);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		reverse_rotate_both(a, b, cheapest_node);
	check_top_of_list_a_1(a, cheapest_node);
	check_top_of_list_b_1(b, cheapest_node);
	pb(b, a);
}

static void	move_b_to_a(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*cheapest_node;

	cheapest_node = find_cheapest(b);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_both_b(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		reverse_rotate_both_b(a, b, cheapest_node);
	check_top_of_list_b_2(b, cheapest_node);
	check_top_of_list_a_2(a, cheapest_node);
	pa(a, b);
}
