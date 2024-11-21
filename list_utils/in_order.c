/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:54:37 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 18:45:51 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	in_order(t_ps_list **list)
{
	t_ps_list	*current;

	current = *list;
	if (!list || !(*list))
		return (0);
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		else
			current = current->next;
	}
	return (1);
}
