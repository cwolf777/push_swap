/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:39:49 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/23 08:52:27 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ps_list	*find_max(t_ps_list **list)
{
	t_ps_list	*current;
	t_ps_list	*max;

	if (!list || !(*list))
		return (NULL);
	current = *list;
	max = current;
	while (current != NULL)
	{
		if (current->nbr > max->nbr)
		{
			max = current;
		}
		current = current->next;
	}
	return (max);
}

t_ps_list	*find_min(t_ps_list **list)
{
	t_ps_list	*current;
	t_ps_list	*min;

	if (!list || !(*list))
		return (NULL);
	current = *list;
	min = current;
	while (current != NULL)
	{
		if (current->nbr < min->nbr)
		{
			min = current;
		}
		current = current->next;
	}
	return (min);
}
