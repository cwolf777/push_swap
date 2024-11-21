/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:53:58 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 18:37:38 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_ps_list	*ft_listlast(t_ps_list *list);

void	rotate(t_ps_list **list)
{
	t_ps_list	*first_node;
	t_ps_list	*last_node;

	if (!(list) || !(*list) || !((*list)->next))
		return ;
	first_node = *list;
	last_node = ft_listlast(*list);
	*list = first_node->next;
	(*list)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
}

void	ra(t_ps_list **a)
{
	rotate(a);
}

void	rb(t_ps_list **b)
{
	rotate(b);
}

static t_ps_list	*ft_listlast(t_ps_list *list)
{
	while (list != NULL)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (0);
}
