/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:20:05 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/30 11:04:56 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_ps_list	*ft_listlast(t_ps_list *list);

static	void	reverse_rotate(t_ps_list **list)
{
	t_ps_list	*last_node;
	t_ps_list	*first_node;

	if (!(list) || !(*list) || !((*list)->next))
		return ;
	last_node = ft_listlast(*list);
	first_node = *list;
	first_node->prev = last_node;
	if (last_node->prev != NULL)
		last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	*list = last_node;
}

void	rra(t_ps_list **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_ps_list **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_ps_list **a, t_ps_list **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
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
