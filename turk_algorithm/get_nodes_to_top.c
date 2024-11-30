/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:03:13 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/30 10:43:21 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_ps_list **a, t_ps_list **b,
			t_ps_list *cheapest_node) //a in titel
{
	if (!a || !b || !cheapest_node || !cheapest_node->target_node)
		return ;
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b);
	update_index_median(a);
	update_index_median(b);
}

void	rotate_both_b(t_ps_list **a, t_ps_list **b,
			t_ps_list *cheapest_node)
{
	if (!a || !b || !cheapest_node || !cheapest_node->target_node)
		return ;
	while (*b != cheapest_node && *a != cheapest_node->target_node)
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

void	reverse_rotate_both_b(t_ps_list **a, t_ps_list **b,
			t_ps_list *cheapest_node)
{
	if (!a || !b || !cheapest_node || !cheapest_node->target_node)
		return ;
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b);
	update_index_median(a);
	update_index_median(b);
}
