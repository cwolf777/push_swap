/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_top_of_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:43:11 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/30 11:24:15 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_top_of_list_a_1(t_ps_list **a, t_ps_list *top_node)
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

void	check_top_of_list_b_1(t_ps_list **b, t_ps_list *cheapest_node)
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

void	check_top_of_list_b_2(t_ps_list **b, t_ps_list *cheapest_node)
{
	if (!b || !(*b) || !cheapest_node)
		return ;
	while (*b != cheapest_node)
	{
		if (cheapest_node->above_median == 1)
			rb(b);
		else
			rrb(b);
	}
}

void	check_top_of_list_a_2(t_ps_list **a, t_ps_list *top_node)
{
	if (!a || !(*a) || !top_node)
		return ;
	while (*a != top_node->target_node)
	{
		if (top_node->target_node->above_median == 1)
			ra(a);
		else
			rra(a);
	}
}
