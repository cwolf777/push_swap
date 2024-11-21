/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:54:06 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 18:47:15 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_ps_list **list)
{
	t_ps_list	*current;

	current = *list;
	if (current->nbr > current->next->nbr
		&& current->nbr > current->next->next->nbr)
	{
		ra(list);
		if (in_order(list) == 1)
			return ;
	}
	else if (current->next->nbr > current->next->next->nbr)
	{
		rra(list);
		if (in_order(list) == 1)
			return ;
	}
	sa(list);
}
