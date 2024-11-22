/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:51:17 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/22 17:54:05 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ps_list	*find_cheapest(t_ps_list **list)
{
	t_ps_list	*current;

	if (!list || !(*list))
		return (NULL);
	current = *list;
	while (current != NULL)
	{
		if (current->cheapest == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}
