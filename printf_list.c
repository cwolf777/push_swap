/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:02:53 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/19 16:41:05 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_ps_list *head)
{
	while (head)
	{
		ft_printf("%d -> ", head->nbr);
		head = head->next;
	}
	ft_printf("NULL\n");
}
