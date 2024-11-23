/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:15:48 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/23 09:53:50 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	update_target(t_ps_list **a, t_ps_list **b);

void	update_nodes_b(t_ps_list **a, t_ps_list **b)
{
	update_index_median(a);
	update_index_median(b);
	update_target(a, b);
}

static void	update_target(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*b_node;
	t_ps_list	*a_node;
	int			closest_target;

	if (!a || !(*a) || !b || !(*b))
		return ;
	b_node = *b;
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
}
