/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:22:44 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/29 15:54:14 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_ps_list **dst, t_ps_list **src)
{
	t_ps_list	*first_src;

	if (!src || !(*src))
		return ;
	first_src = *src;
	*src = first_src->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	first_src->next = *dst;
	first_src->prev = NULL;
	if (*dst != NULL)
		(*dst)->prev = first_src;
	*dst = first_src;
}

void	pa(t_ps_list **a, t_ps_list **b)
{
	ft_printf("pa\n");
	push(a, b);
}

void	pb(t_ps_list **b, t_ps_list **a)
{
	ft_printf("pb\n");
	push(b, a);
}
