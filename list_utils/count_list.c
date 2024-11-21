/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:20:19 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 20:01:59 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_list_len(t_ps_list **list)
{
	t_ps_list	*current;
	int			count;

	current = *list;
	count = 0;
	if (!list || !(*list))
		return (0);
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	two_nodes(t_ps_list **list)
{
	t_ps_list	*current;
	int			count;

	current = *list;
	count = 0;
	if (!list || !(*list))
		return (0);
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}

int	three_nodes(t_ps_list **list)
{
	t_ps_list	*current;
	int			count;

	current = *list;
	count = 0;
	if (!list || !(*list))
		return (0);
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	if (count == 3)
		return (1);
	else
		return (0);
}
