/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:03:13 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/23 09:31:11 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_ps_list **a, t_ps_list **b,
			t_ps_list *cheapest_node)
{
	if (!a || !b || !cheapest_node || !cheapest_node->target_node)
		return ;
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b);
	update_index_median(a);
	update_index_median(b);
}

void	reverse_rotate_both(t_ps_list **a, t_ps_list **b,
			t_ps_list *cheapest_node)
{
	if (!a || !b || !cheapest_node || !cheapest_node->target_node)
		return ;
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b);
	update_index_median(a);
	update_index_median(b);
}

void	check_top_of_list_a(t_ps_list **a, t_ps_list *top_node)
{
	if (!a || !(*a) || !top_node)
		return ;
	while (*a != top_node)
	{
		if (top_node->above_median == 1)
			ra(a);
		else
			rra(a);
	}
}

void	check_top_of_list_b(t_ps_list **b, t_ps_list *cheapest_node)
{
	if (!b || !(*b) || !cheapest_node)
		return ;
	while (*b != cheapest_node->target_node)
	{
		if (cheapest_node->target_node->above_median == 1)
			rb(b);
		else
			rrb(b);
	}
}
