/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:15:48 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/30 10:03:38 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	update_target(t_ps_list **a, t_ps_list **b);
static void	update_push_cost(t_ps_list **a, t_ps_list **b);

void	update_nodes_b(t_ps_list **a, t_ps_list **b)
{
	update_index_median(a);
	update_index_median(b);
	update_target(a, b);
	update_push_cost(a, b);
	update_cheapest(b);
}

static void	update_target(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*b_node;
	t_ps_list	*a_node;
	int			closest_target;

	if (!a || !(*a) || !b || !(*b))
		return ;
	b_node = *b;
	while (b_node != NULL)
	{
		a_node = *a;
		closest_target = INT_MAX;
		while (a_node != NULL)
		{
			if (a_node->nbr > b_node->nbr && a_node->nbr < closest_target)
			{
				closest_target = a_node->nbr;
				b_node->target_node = a_node;
			}
			a_node = a_node->next;
		}
		if (closest_target == INT_MAX)
			b_node->target_node = find_min(a);
		b_node = b_node->next;
	}
}

static void	update_push_cost(t_ps_list **a, t_ps_list **b)
{
	int			len_a;
	int			len_b;
	t_ps_list	*a_node;
	t_ps_list	*b_node;

	if (!a || !b || !(*a) || !(*b))
		return ;
	a_node = *a;
	b_node = *b;
	len_a = count_list_len(a);
	len_b = count_list_len(b);
	while (b_node != NULL)
	{
		if (b_node->above_median == 1)
			b_node->push_cost = b_node->index;
		else
			b_node->push_cost = len_b - b_node->index;
		if (b_node->target_node->above_median == 1)
			b_node->push_cost += b_node->target_node->index;
		else
			b_node->push_cost += len_a - b_node->target_node->index;
		b_node = b_node->next;
	}
}
