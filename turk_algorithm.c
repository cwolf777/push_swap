/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:20:16 by cwolf             #+#    #+#             */
/*   Updated: 2024/11/21 22:28:32 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algorithm(t_ps_list **a, t_ps_list **b)
{
	int	len_a;

	len_a = count_list_len(a);
	if (len_a >= 4 && in_order(a) == 0)
	{
		pb(b, a);
		len_a = len_a - 1; //brauch ich hier kein update der nodes?
	}
	if (len_a >= 4 && in_order(a) == 0)
	{
		pb(b, a);
		len_a = len_a - 1;
	}
	while (len_a >= 4 && in_order(a) == 0)
	{
		update_notes(a, b);
		//node von a zu b
		len_a = len_a - 1;
	}
	//sort three a
	//solange in b nodes
		//updaten von b nodes
		//von b zu a
	//checken ob kleinste zahl oben ist
	
}
