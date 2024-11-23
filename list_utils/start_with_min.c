/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_with_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:36:58 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/23 09:41:06 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_with_min(t_ps_list **list)
{
	t_ps_list	*min_node;

	min_node = find_min(list);
	while (*list != min_node)
	{
		if (min_node->above_median == 1)
			ra(list);
		else
			rra(list);
	}
}
