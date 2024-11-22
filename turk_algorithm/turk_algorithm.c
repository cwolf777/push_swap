/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:20:16 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/22 19:23:20 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_a_to_b(t_ps_list **a, t_ps_list **b);

void	turk_algorithm(t_ps_list **a, t_ps_list **b)
{
	int	len_a;

	len_a = count_list_len(a);
	if (len_a >= 4 && in_order(a) == 0)
	{
		pb(b, a);
		len_a = len_a - 1; //brauch ich hier kein update der nodes?
	}
	if (len_a >= 4 && in_order(a) == 0)
	{
		pb(b, a);
		len_a = len_a - 1;
	}
	while (len_a >= 4 && in_order(a) == 0)
	{
		update_notes(a, b);
		move_a_to_b(a, b);
		len_a = len_a - 1;
	}
	sort_three(a);
	//solange in b nodes
		//updaten von b nodes
		//von b zu a
	//checken ob kleinste zahl oben ist
}

static void	move_a_to_b(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*cheapest_node;

	cheapest_node = find_cheapest(a);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 0)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		reverse_rotate_both(a, b, cheapest_node);
	check_top_of_list_a(a, cheapest_node);
	check_top_of_list_b(b, cheapest_node);
	pb(b, a);
}
