/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:08:48 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/09 09:18:41 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list_end(t_ps_list **a)
{
	t_ps_list	*temp;
	t_ps_list	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current != NULL)
	{
		temp = current->next;
		current->nbr = -1;
		free(current);
		current = temp;
	}
	*a = NULL;
	return ;
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
