/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:01:44 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 18:37:43 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_ps_list **list)
{
	t_ps_list	*first;
	t_ps_list	*second;

	if (!(*list) || !((*list)->next))
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*list = second;
}

void	sa(t_ps_list **a)
{
	swap(a);
}

void	sb(t_ps_list **b)
{
	swap(b);
}

void	ss(t_ps_list **a, t_ps_list **b)
{
	swap(a);
	swap(b);
}
