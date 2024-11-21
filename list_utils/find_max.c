/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:39:49 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 20:47:30 by cwolf            ###   ########.fr       */
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
