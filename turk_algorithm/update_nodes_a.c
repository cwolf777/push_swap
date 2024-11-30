/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:46:46 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/30 10:00:53 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		update_cheapest(t_ps_list	**list);
void		update_index_median(t_ps_list **list);
static void	update_push_cost(t_ps_list **a, t_ps_list **b);
static void	update_target(t_ps_list **a, t_ps_list **b);

void	update_notes_a(t_ps_list **a, t_ps_list **b)
{
	update_index_median(a);
	update_index_median(b);
	update_target(a, b);
	update_push_cost(a, b);
	update_cheapest(a);
}

void	update_index_median(t_ps_list **list)
{
	t_ps_list	*current;
	int			index;
	int			median;

	current = *list;
	index = 0;
	median = count_list_len(list) / 2;
	if (!list && !(*list))
		return ;
	while (current != NULL)
	{
		current->index = index;
		if (index <= median)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
		index++;
	}
}

static void	update_target(t_ps_list **a, t_ps_list **b)
{
	t_ps_list	*b_node;
	t_ps_list	*a_node;
	int			closest_target;

	if (!a || !(*a) || !b || !(*b))
		return ;
	a_node = *a;
	while (a_node != NULL)
	{
		b_node = *b;
		closest_target = INT_MIN;
		while (b_node != NULL)
		{
			if (b_node->nbr < a_node->nbr && b_node->nbr > closest_target)
			{
				closest_target = b_node->nbr;
				a_node->target_node = b_node;
			}
			b_node = b_node->next;
		}
		if (closest_target == INT_MIN)
			a_node->target_node = find_max(b);
		a_node = a_node->next;
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
	while (a_node != NULL)
	{
		if (a_node->above_median == 1)
			a_node->push_cost = a_node->index;
		else
			a_node->push_cost = len_a - a_node->index;
		if (a_node->target_node->above_median == 1)
			a_node->push_cost += a_node->target_node->index;
		else
			a_node->push_cost += len_b - a_node->target_node->index;
		a_node = a_node->next;
	}
}

void	update_cheapest(t_ps_list	**list)
{
	t_ps_list	*current;
	t_ps_list	*cheapest_node;
	int			cheapest_cost;

	if (!list || !(*list))
		return ;
	cheapest_cost = INT_MAX;
	current = *list;
	while (current != NULL)
	{
		current->cheapest = 0;
		if (current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = 1;
}
